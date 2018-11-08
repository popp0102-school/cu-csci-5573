#include "memorydumper.h"

//Virtual Memory Gather
long long MemoryDumper::GetCurrentVirtualMemory(void)
{
  sysinfo(&memInfo);
  long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
  virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
  virtualMemUsed *= memInfo.mem_unit;
  return virtualMemUsed;
}

long long MemoryDumper::GetTotalVirtualMemory(void)
{
  sysinfo(&memInfo);
  long long totalVirtualMem = memInfo.totalram;
  totalVirtualMem += memInfo.totalswap;
  totalVirtualMem *= memInfo.mem_unit;
  return totalVirtualMem;
}

int MemoryDumper::GetVirtualMemoryFromProcess(void)
{
  return GetFileInformationVirtual();
}

//CPU Information
double MemoryDumper::GetCPUInfoFromProcess(void)
{
  unsigned long long lastTotalUser=0ULL, lastTotalUserLow=0ULL, lastTotalSys=0ULL, lastTotalIdle=0ULL;
  double percent=0.0;
  unsigned long long totalUser=0ULL, totalUserLow=0ULL, totalSys=0ULL, totalIdle=0ULL;
  try
  {
    std::FILE* file = std::fopen("/proc/stat", "r");
    std::fscanf(file, "cpu %llu %llu %llu %llu", &lastTotalUser, &lastTotalUserLow, &lastTotalSys, &lastTotalIdle);
    std::fclose(file);

    file = std::fopen("/proc/stat","r");
    std::fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow, &totalSys, &totalIdle);
    std::fclose(file);
  }
  catch(std::exception& e)
  {
    std::cout << '\n' << e.what() << '\n';
    throw e;
  }

  if(totalUser < lastTotalUser || totalUserLow < lastTotalUserLow || totalSys < lastTotalSys || totalIdle < lastTotalIdle)
  {
    //Overflow dtection, skip value...
    percent = -1.0;
  }
  else
  {
    double total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) + (totalSys - lastTotalSys);
    percent = total;
    total += (totalIdle - lastTotalIdle);
    percent /= total;
    percent *= 100;
  }

  lastTotalUser = totalUser;
  lastTotalUserLow = totalUserLow;
  lastTotalSys = totalSys;
  lastTotalIdle = totalIdle;
  return percent;
}

int MemoryDumper::ParseLine(char* line)
{
  //Digit found and will have line ending with " KB"...
  int i = std::strlen(line);
  const char *num = line;
  while(*num <'0' || *num > '9')
  {
    num++;
  }
  line[i-3] = '\0';
  i = atoi(num);
  return i;
}

int MemoryDumper::GetFileInformationVirtual()
{
  std::FILE* file = std::fopen("/proc/self/status", "r");
  int result = -1;
  char line[128];

  while (fgets(line, 128, file) != NULL)
  {
    if(std::strncmp(line, "VmSize: ", 7) == 0)
    {
      result = ParseLine(line);
      break;
    }
  }
  std::fclose(file);
  return result;
}

