# Locations
BUILD_DIR = $(CURDIR)/build
APP       = $(BUILD_DIR)/modulusPrime

SRC_DIR   = $(CURDIR)
OS_DIR    = $(SRC_DIR)/os
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) \
            $(wildcard $(OS_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Compiler
CXXFLAGS = -Wall -g
LDFLAGS  =
INCLUDES = -I $(OS_DIR)

app: create_build_dir modulus-prime

modulus-prime: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(APP) $(LDFLAGS)
	if [ -d "$(BIN_DIR)" ]; then ln -srf $(APP) $(BIN_DIR); fi

create_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean create_build_dir

