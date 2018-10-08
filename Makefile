BIN_DIR = $(CURDIR)/bin
SRC_DIR = $(CURDIR)/src
OS_DIR  = $(SRC_DIR)/os

CXXFLAGS = -Wall -g
LDFLAGS  =
INCLUDES = -I $(OS_DIR)

src_files   = $(wildcard $(SRC_DIR)/*.cpp) \
              $(wildcard $(OS_DIR)/*.cpp)
obj_files   = $(src_files:.c=.o)
app         = modulusPrime

export BIN_DIR

app: create_bin modulus-prime

modulus-prime: $(obj_files)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o bin/$(app) $(LDFLAGS)

create_bin:
	mkdir -p $(BIN_DIR)

tests: create_bin
	$(MAKE) -C test tests

install_gtest:
	sudo apt-get --yes install libgtest-dev
	sudo apt-get --yes install cmake
	sudo cmake /usr/src/gtest/CMakeLists.txt
	sudo make -C /usr/src/gtest
	sudo cp /usr/src/gtest/*.a /usr/lib

clean:
	rm -rf $(BIN_DIR)
	$(MAKE) -C test clean

.PHONY: clean
