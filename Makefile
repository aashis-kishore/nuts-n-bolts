OUT_DIR="build"

all: build

build:
	mkdir -p $(OUT_DIR)
	cd $(OUT_DIR) && cmake .. && make

.phony: clean

clean:
	rm -rf $(OUT_DIR)
