#include <limits.h>
#include <gtest/gtest.h>
#include "memorydumper.h"
#include <iostream>
TEST(MemoryDumper, GetCurrentVirtualMemory)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetCurrentVirtualMemory(), 1);
	std::cout << md->GetCurrentVirtualMemory() << std::endl;
	EXPECT_NO_THROW(md->GetCurrentVirtualMemory());
};

TEST(MemoryDumper, GetTotalVirtualMemory)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetTotalVirtualMemory(), 1);
	std::cout << md->GetTotalVirtualMemory() << std::endl;
	EXPECT_NO_THROW(md->GetTotalVirtualMemory());
};

TEST(MemoryDumper, GetVirtualMemoryFromProcess)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetVirtualMemoryFromProcess(), 1);
	std::cout << md->GetVirtualMemoryFromProcess() << std::endl;
	EXPECT_NO_THROW(md->GetVirtualMemoryFromProcess());
};

TEST(MemoryDumperCPU, GetCPUInfoFromProcess)
{
        MemoryDumper *md = new MemoryDumper();
	unsigned long long test = 0ULL;
	unsigned long long expect = md->GetCPUInfoFromProcess();
        ASSERT_GE(expect, test);
        EXPECT_NO_THROW(md->GetCPUInfoFromProcess());
};
