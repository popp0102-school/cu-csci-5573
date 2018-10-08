BIN_DIR   = $(CURDIR)/bin
GTEST_DIR = /usr/src/gtest

export BIN_DIR

all: app tests

app: create_bin
	$(MAKE) -C src app

tests: create_bin
	$(MAKE) -C test tests

create_bin:
	mkdir -p $(BIN_DIR)

install:
	sudo apt-get --yes install libgtest-dev
	sudo apt-get --yes install cmake
	sudo cmake $(GTEST_DIR)/CMakeLists.txt
	sudo make -C $(GTEST_DIR)
	sudo cp $(GTEST_DIR)/*.a /usr/lib

clean:
	rm -rf $(BIN_DIR)
	$(MAKE) -C src clean
	$(MAKE) -C test clean

.PHONY: clean

