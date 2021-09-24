OUT_DIR="build"

all: build

build:
	mkdir -p $(OUT_DIR)
	cd $(OUT_DIR) && cmake .. && make

test: build
	cd $(OUT_DIR) && ctest

.phony: clean

clean:
	rm -rf $(OUT_DIR)
