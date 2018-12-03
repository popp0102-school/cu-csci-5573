NAME     := modulusPrime
TESTAPP  := runTests

DEMO     := demo
DEMO1    := $(DEMO)-1
DEMO2    := $(DEMO)-2
DEMO3    := $(DEMO)-3
DEMO4    := $(DEMO)-4
DEMO5    := $(DEMO)-5
DEMO6    := $(DEMO)-6

BINDIR   := bin
SRCDIR   := src
PRGMDIR  := src/programs
TESTDIR  := test

CXX      := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread -lboost_system
INCLUDES := -I ./include/os -I include/lib

DEMOSRC1  := $(PRGMDIR)/demo-1.cpp
DEMOSRC2  := $(PRGMDIR)/demo-2.cpp
DEMOSRC3  := $(PRGMDIR)/demo-3.cpp
DEMOSRC4  := $(PRGMDIR)/demo-4.cpp
DEMOSRC5  := $(PRGMDIR)/demo-5.cpp
DEMOSRC6  := $(PRGMDIR)/demo-6.cpp

SRCFILES  := $(shell find $(SRCDIR) -type f -name '*.cpp' -not -path "$(PRGMDIR)/*")
TESTFILES := $(shell find $(TESTDIR) -type f -name '*cpp')

all: clean demos test
demo: clean demos
demos: demo1 demo2 demo3 demo4 demo5 demo6

demo1: $(BINDIR)/$(DEMO1)
demo2: $(BINDIR)/$(DEMO2)
demo3: $(BINDIR)/$(DEMO3)
demo4: $(BINDIR)/$(DEMO4)
demo5: $(BINDIR)/$(DEMO5)
demo6: $(BINDIR)/$(DEMO6)

test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(DEMO1):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC1) -o $@ $(LDFLAGS)

$(BINDIR)/$(DEMO2):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC2) -o $@ $(LDFLAGS)

$(BINDIR)/$(DEMO3):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC3) -o $@ $(LDFLAGS)

$(BINDIR)/$(DEMO4):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC4) -o $@ $(LDFLAGS)

$(BINDIR)/$(DEMO5):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC5) -o $@ $(LDFLAGS)

$(BINDIR)/$(DEMO6):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(DEMOSRC6) -o $@ $(LDFLAGS)

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(DEMO)* $(BINDIR)/$(NAME)* $(BINDIR)/$(TESTAPP)* *.txt

.PHONY: install clean
