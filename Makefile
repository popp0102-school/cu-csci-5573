APP      := modulusPrime
TESTAPP  := runTests
BINDIR   := bin
SRCDIR   := src
TESTDIR  := test

CXX      := g++
LINKER   := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread -lboost_system
INCLUDES := -I ./include/*

SRCFILES  := $(shell find $(SRCDIR) -type f -name '*.cpp' -not -path $(SRCDIR)/main.cpp)
APPFILES  := $(SRCFILES) $(SRCDIR)/main.cpp
TESTFILES := $(shell find $(TESTDIR) -type f -name '*cpp')

all: clean app test

app: $(BINDIR)/$(APP)

test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(APPFILES) -o $@ $(LDFLAGS)

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(APP)* $(BINDIR)/$(TESTAPP)*

.PHONY: clean

