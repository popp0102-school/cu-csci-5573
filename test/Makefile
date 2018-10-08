# Locations
BUILD_DIR = $(CURDIR)/build
TEST_APP  = $(BUILD_DIR)/runTests

tests: create_build_dir
	cd build && cmake .. && make
	if [ -d "$(BIN_DIR)" ]; then ln -srf $(TEST_APP) $(BIN_DIR); fi

create_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean create_build_dir

