OUT_DIR=build
CC=gcc
CFLAGS=-Werror -Wpedantic

all: trie

run-trie: trie
	@echo
	./build/trie

trie: src/*.c
	mkdir -p $(OUT_DIR)
	$(CC) $^ -o $(OUT_DIR)/$@ $(CFLAGS)

.phony: clean

clean:
	rm -rf $(OUT_DIR)


