# Locations
TEST_DIR    = $(CURDIR)
BUILD_DIR   = $(TEST_DIR)/build
TEST_APP    = $(BUILD_DIR)/runTests
OS_TEST_DIR = $(TEST_DIR)/os
TEST_FILES  = $(wildcard $(TEST_DIR)/*.cpp) \
              $(wildcard $(OS_TEST_DIR)/*.cpp)
OBJ_FILES   = $(TEST_FILES:.c=.o)

# Compiler
LD_FLAGS   = -lgtest -lpthread
CXX_FLAGS  = -Wall -g -std=c++11
INCLUDES   =

tests: create_build_dir test_app
	if [ -d "$(BIN_DIR)" ]; then ln -sf $(TEST_APP) $(BIN_DIR); fi

test_app:
	$(CXX) $(CXX_FLAGS) $(INCLUDES) main.cpp os/scheduler_test.cpp -o $(TEST_APP) $(LD_FLAGS)

create_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean create_build_dir

