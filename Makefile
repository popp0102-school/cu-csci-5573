APP      := modulusPrime
TESTAPP  := runTests
BINDIR   := bin
SRCDIR   := src

CXX      := g++
LINKER   := g++
CXXFLAGS := -Wall -std=c++11 -g
LDFLAGS  := -lgtest -lpthread
INCLUDES := -I ./include

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(SRCFILES:.cpp=.o)
DEPFILES := $(SRCFILES:.cpp=.d)

all: app test

app: $(BINDIR)/$(APP)

test: $(BINDIR)/$(TESTAPP)

$(BINDIR)/$(APP): $(OBJFILES)
	$(LINKER) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.d: %.cpp
	$(CXX) $(INCLUDES) -MM $< > $@

$(BINDIR)/$(TESTAPP):
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/scheduler.cpp test/main.cpp test/scheduler_test.cpp -o $@ $(LDFLAGS)

install:
	bin/install

clean:
	rm -rf $(BINDIR)/$(APP)* $(BINDIR)/$(TESTAPP)* $(SRCDIR)/*.o $(SRCDIR)/*.d

-include $(DEPFILES)

.PHONY: clean

