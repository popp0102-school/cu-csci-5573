SRC_DIR  = $(CURDIR)
OS_DIR   = $(SRC_DIR)/os

CXXFLAGS = -Wall -g
LDFLAGS  =
INCLUDES = -I $(OS_DIR)


SRC_FILES   = $(wildcard $(SRC_DIR)/*.cpp) \
              $(wildcard $(OS_DIR)/*.cpp)
OBJ_FILES   = $(SRC_FILES:.c=.o)
APP         = modulusPrime

modulus-prime: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $(APP) $(LDFLAGS)
	if [ -d "$(BIN_DIR)" ]; then ln -srf $(SRC_DIR)/$(APP) $(BIN_DIR); fi

clean:
	rm $(APP)

.PHONY: clean

