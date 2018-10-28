NAME     := modulusPrime
APP1     := $(NAME)-1
APP2     := $(NAME)-2
TESTAPP  := runTests

BINDIR   := bin
SRCDIR   := src
TESTDIR  := test

CXX      := g++
LINKER   := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread -lboost_system
INCLUDES := -I ./include/os -I include/lib

SRCFILES  := $(shell find $(SRCDIR) -type f -name '*.cpp' -not -path "$(SRCDIR)/programs/main-*")
APP1FILES := $(SRCFILES) $(SRCDIR)/programs/main-1.cpp
APP2FILES := $(SRCFILES) $(SRCDIR)/programs/main-2.cpp
TESTFILES := $(shell find $(TESTDIR) -type f -name '*cpp')

all: clean app1 app2 test

app1: $(BINDIR)/$(APP1)
app2: $(BINDIR)/$(APP2)
test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP1):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(APP1FILES) -o $@ $(LDFLAGS)

$(BINDIR)/$(APP2):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(APP2FILES) -o $@ $(LDFLAGS)

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(NAME)* $(BINDIR)/$(TESTAPP)*

.PHONY: clean

