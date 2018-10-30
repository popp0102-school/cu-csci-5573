#include <limits.h>
#include <gtest/gtest.h>
#include "memorydumper.h"

TEST(MemoryDumper, GetCurrentVirtualMemory)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetCurrentVirtualMemory(), 1);
	EXPECT_NO_THROW(md->GetCurrentVirtualMemory());
};

TEST(MemoryDumper, GetTotalVirtualMemory)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetTotalVirtualMemory(), 1);
	EXPECT_NO_THROW(md->GetTotalVirtualMemory());
};

TEST(MemoryDumper, GetVirtualMemoryFromProcess)
{
	MemoryDumper *md = new MemoryDumper();
	ASSERT_GE(md->GetVirtualMemoryFromProcess(), 1);
	EXPECT_NO_THROW(md->GetVirtualMemoryFromProcess());
};

TEST(MemoryDumper, GetTotalPhysicalMemory)
{
        MemoryDumper *md = new MemoryDumper();
        ASSERT_GE(md->GetTotalPhysicalMemory(), 1);
        EXPECT_NO_THROW(md->GetTotalPhysicalMemory());
};

TEST(MemoryDumper, GetCurrentPhysicalMemory)
{
        MemoryDumper *md = new MemoryDumper();
        ASSERT_GE(md->GetCurrentPhysicalMemory(), 1);
        EXPECT_NO_THROW(md->GetCurrentPhysicalMemory());
};

TEST(MemoryDumper, GetPhysicalMemoryFromProcess)
{
        MemoryDumper *md = new MemoryDumper();
        ASSERT_GE(md->GetPhysicalMemoryFromProcess(), 1);
        EXPECT_NO_THROW(md->GetPhysicalMemoryFromProcess());
};

TEST(MemoryDumperCPU, GetCPUInfoFromProcess)
{
        MemoryDumper *md = new MemoryDumper();
	unsigned long long test = 0ULL;
	unsigned long long expect = md->GetCPUInfoFromProcess();
        ASSERT_GE(expect, test);
        EXPECT_NO_THROW(md->GetCPUInfoFromProcess());
};
