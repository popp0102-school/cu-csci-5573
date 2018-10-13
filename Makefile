APP      := modulusPrime
TESTAPP  := runTests
BINDIR   := bin
SRCDIR   := src/os
TESTDIR  := test
BUILDDIR := build

CXX      := g++
LINKER   := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread
INCLUDES := -I ./include

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCFILES))

TESTFILES := $(wildcard $(TESTDIR)/*.cpp)

all: app test

app: $(BINDIR)/$(APP)

test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP): $(OBJFILES) build/main.o
	$(LINKER) $(CXXFLAGS) $^ -o $@

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCFILES) $(TESTFILES) -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(APP)* $(BINDIR)/$(TESTAPP)* $(BUILDDIR)/*

.PHONY: clean

