TEST_BUILD_DIR = $(CURDIR)/build
TEST_APP       = runTests

tests:
	cd build && cmake .. && make
	if [ -d "$(BIN_DIR)" ]; then ln -sr $(TEST_BUILD_DIR)/$(TEST_APP) $(BIN_DIR); fi

clean:
	rm -rf $(TEST_BUILD_DIR)/*

.PHONY: clean

