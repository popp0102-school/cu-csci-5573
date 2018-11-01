#ifndef MP_STACKTRACE
#define MP_STACKTRACE

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <cxxabi.h>

inline void GetStackTrace(FILE *out=stderr, unsigned int maxFrames=63)
{

	fprintf(out, "stack trace:\n");
	void *addrlist[maxFrames + 1];
	int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));

	if(addrlen == 0)
	{
		fprintf(out, "  <empty, error may be corrupt>\n");
		return;
	}

	//Resolve addresses to string as filename(function+address)
	char** symbollist = backtrace_symbols(addrlist, addrlen);

	size_t funcnamesize = 256;
	char *funcname = (char*)malloc(funcnamesize);

	for(int i = 1; i < addrlen; i++)
	{
	  char *beginName = 0;
	  char *beginOffset = 0;
	  char *endOffset = 0;

	  //Find the parentheses and address offset of mangled name
	  //e.g. ./module(function+0x15c) [0x8048a6d]
	  for(char *p = symbollist[i]; *p; ++p)
	  {
			if(*p == '(')
			{
		   	beginName = p;
			}
	    else if(*p == '+')
			{
		   	beginName = p;
			}
			else if (*p == ')' && beginOffset)
			{
		   	endOffset = p;
		   	break;
			}
	  }
		if(beginName && beginOffset && endOffset && beginName < beginOffset)
		{
	  	//Add string null terminal at end to complete string...
	  	*beginName++ = '\0';
	  	*beginOffset++ = '\0';
	  	*endOffset = '\0';

	  	//Mangled name in [beginName, beginOffset] caller and
	  	//[beginOffset, endOffset] now apply __cxa__demangle();
	  	int status;
	  	char* ret = abi::__cxa_demangle(beginName, funcname, &funcnamesize, &status);
	  	if(status == 0)
	  	{
				funcname = ret; //realloc(ed) string
				fprintf(out, " %s : %s+%s\n", symbollist[i], funcname, beginOffset);
	  	}
	  	else
			{
				fprintf(out, " %s : %s()+%s\n", symbollist[i], beginName, beginOffset);
	  	}
		}
		else
		{
			//Demangling failed output func name as a c func with no args
			fprintf(out, " %s\n", symbollist[i]);
		}
	}
 free(funcname);
 free(symbollist);
}

#endif
