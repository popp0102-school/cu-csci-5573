NAME     := modulusPrime
APP1     := $(NAME)-1
APP2     := $(NAME)-2
APP3	 := $(NAME)-3
APP4	 := $(NAME)-4
APP1RR   := $(NAME)-1RR
TESTAPP  := runTests

BINDIR   := bin
SRCDIR   := src
PRGMDIR  := src/programs
TESTDIR  := test

CXX      := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread -lboost_system
INCLUDES := -I ./include/os -I include/lib

MAIN1     := $(PRGMDIR)/main-1.cpp
MAIN2     := $(PRGMDIR)/main-2.cpp
MAIN3	  := $(PRGMDIR)/main-3.cpp
MAIN4	  := $(PRGMDIR)/main-4.cpp
MAIN1RR   := $(PRGMDIR)/main-1Rerun.cpp
SRCFILES  := $(shell find $(SRCDIR) -type f -name '*.cpp' -not -path "$(PRGMDIR)/*")
TESTFILES := $(shell find $(TESTDIR) -type f -name '*cpp')

all: clean app1 app2 app3 app4 app1RR test

app1: $(BINDIR)/$(APP1)
app2: $(BINDIR)/$(APP2)
app3: $(BINDIR)/$(APP3)
app4: $(BINDIR)/$(APP4)
app1RR: $(BINDIR)/$(APP1RR)
test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP1):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN1) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP2):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN2) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP3):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN3) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP4):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN4) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP1RR):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN1RR) -o $@ $(LDFLAGS)

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(NAME)* $(BINDIR)/$(TESTAPP)*

.PHONY: install clean
