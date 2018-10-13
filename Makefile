UNAME         = $(shell uname)
GTEST_SRC_DIR = /usr/src/gtest

export BINDIR
export UNAME


BINDIR   = bin
SRCDIR   = src
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(SRCFILES:.c=.o)

CXXFLAGS = -Wall -std=c++11 -g
LD_FLAGS = -lgtest -lpthread
INCLUDES = -I ./src

all: app tests

app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(BINDIR)/modulusPrime $(LD_FLAGS)

tests:
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/scheduler.cpp test/main.cpp test/scheduler_test.cpp -o $(BINDIR)/runTests $(LD_FLAGS)

install:
ifeq ($(UNAME), Darwin)
	$(MAKE) gtest_install_mac
else
	$(MAKE) gtest_install_linux
endif

gtest_install_mac:
	brew install cmake
	git clone https://github.com/google/googletest
	mkdir -p googletest/build
	cmake googletest/CMakeLists.txt
	cd googletest make && make install
	rm -rf googletest

gtest_install_linux:
	sudo apt-get --yes install libgtest-dev
	sudo apt-get --yes install cmake
	sudo cmake $(GTEST_SRC_DIR)/CMakeLists.txt
	sudo make -C $(GTEST_SRC_DIR)
	sudo cp $(GTEST_SRC_DIR)/*.a /usr/lib

clean:
	rm -rf $(BINDIR)/modulusPrime* $(BINDIR)/runTests*

.PHONY: clean

