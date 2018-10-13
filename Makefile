UNAME         = $(shell uname)
BIN_DIR       = $(CURDIR)/bin
GTEST_SRC_DIR = /usr/src/gtest

export BIN_DIR
export UNAME

all: app tests

app: create_bin
	$(MAKE) -C src app

tests: create_bin
	$(MAKE) -C test tests

create_bin:
	mkdir -p $(BIN_DIR)

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
	rm -rf $(BIN_DIR)
	$(MAKE) -C src clean
	$(MAKE) -C test clean

.PHONY: clean

