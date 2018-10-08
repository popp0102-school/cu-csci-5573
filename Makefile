export BIN_DIR = $(CURDIR)/bin

all: app tests

app: create_bin
	$(MAKE) -C src modulus-prime

tests: create_bin
	$(MAKE) -C test tests

create_bin:
	mkdir -p $(BIN_DIR)

install:
	sudo apt-get --yes install libgtest-dev
	sudo apt-get --yes install cmake
	sudo cmake /usr/src/gtest/CMakeLists.txt
	sudo make -C /usr/src/gtest
	sudo cp /usr/src/gtest/*.a /usr/lib

clean:
	rm -rf $(BIN_DIR)
	$(MAKE) -C test clean

.PHONY: clean

