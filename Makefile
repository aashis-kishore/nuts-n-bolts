OUT_DIR="build"

all: build

build:
	@mkdir -p $(OUT_DIR)
	@cd $(OUT_DIR) && cmake .. && make

build-test:
	@mkdir -p $(OUT_DIR)
	@cd $(OUT_DIR) && cmake .. -DBUILD_TESTS=ON && make

test: build
	@cd $(OUT_DIR) && ctest

.phony: clean

clean:
	@rm -rf $(OUT_DIR)
