src_dir        = ./src
os_dir         = $(src_dir)/os
test_build_dir = ./test/build

CXXFLAGS = -Wall -g
LDFLAGS  =
INCLUDES = -I $(os_dir)

src_files = $(wildcard $(src_dir)/*.cpp) \
            $(wildcard $(os_dir)/*.cpp)
obj_files = $(src:.c=.o)
target    = bin/modulus-prime

modulus-prime: $(obj)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(target) $(LDFLAGS)

tests:
	cd test/build && cmake .. && make
	$(test_build_dir)/runTests

install_gtest:
	sudo apt-get --yes install libgtest-dev
	sudo apt-get --yes install cmake
	sudo cmake /usr/src/gtest/CMakeLists.txt
	sudo make -C /usr/src/gtest
	sudo cp /usr/src/gtest/*.a /usr/lib

clean:
	rm -rf $(target) $(test_build_dir)/*

.PHONY: clean
