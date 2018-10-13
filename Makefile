BINDIR   = bin
SRCDIR   = src
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(SRCFILES:.cpp=.o)

CXXFLAGS = -Wall -std=c++11 -g
LD_FLAGS = -lgtest -lpthread
INCLUDES = -I ./src

all: app tests

app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(BINDIR)/modulusPrime $(LD_FLAGS)

tests:
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/scheduler.cpp test/main.cpp test/scheduler_test.cpp -o $(BINDIR)/runTests $(LD_FLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/modulusPrime* $(BINDIR)/runTests*

.PHONY: clean

