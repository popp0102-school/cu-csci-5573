APP      := modulusPrime
TESTAPP  := runTests
BINDIR   := bin
SRCDIR   := src

CXX      := g++
CXXFLAGS := -Wall -std=c++11 -g
LD_FLAGS := -lgtest -lpthread
INCLUDES := -I ./src

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(SRCFILES:.cpp=.o)


all: app tests

app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(BINDIR)/$(APP) $(LD_FLAGS)

tests:
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/scheduler.cpp test/main.cpp test/scheduler_test.cpp -o $(BINDIR)/$(TESTAPP) $(LD_FLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(APP)* $(BINDIR)/$(TESTAPP)*

.PHONY: clean

