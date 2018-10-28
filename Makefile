NAME     := modulusPrime
APP1     := $(NAME)-1
APP2     := $(NAME)-2
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
SRCFILES  := $(shell find $(SRCDIR) -type f -name '*.cpp' -not -path "$(PRGMDIR)/*")
TESTFILES := $(shell find $(TESTDIR) -type f -name '*cpp')

all: clean app1 app2 test

app1: $(BINDIR)/$(APP1)
app2: $(BINDIR)/$(APP2)
test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP1):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN1) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP2):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(MAIN2) -o $@ $(LDFLAGS)

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(NAME)* $(BINDIR)/$(TESTAPP)*

.PHONY: clean

