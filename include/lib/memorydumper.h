#ifndef MEMORYDUMPER_H
#define MEMORYDUMPER_H
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/times.h>
#include <sys/vtimes.h>
#include <string>
#include <cstring>
#include <sys/ptrace.h>
#include <exception>
#include <iostream>

class MemoryDumper
{
  public:
    //Constructors
    MemoryDumper();
    MemoryDumper(const MemoryDumper& md);
    ~MemoryDumper();

    //Virtual Memory Gather
    long long GetCurrentVirtualMemory(void);
    long long GetTotalVirtualMemory(void);
    int GetVirtualMemoryFromProcess(void);

    //Physical Memory Gather
    long long GetTotalPhysicalMemory(void);
    long long GetCurrentPhysicalMemory(void);
    int GetPhysicalMemoryFromProcess(void);

    //CPU Information
    double GetCPUInfoFromProcess(void);

  private:
    int ParseLine(char* line);
    int GetFileInformationVirtual();
    int GetFileInformationPhysical();
    struct sysinfo memInfo;
};
#endif
