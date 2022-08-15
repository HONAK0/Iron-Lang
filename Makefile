.DEFAULT_GOAL := all

.PHONY: build run all

build:
	gcc src/*.c -o Iron-lang
run:
	./Iron-lang exaples/test.in
all: build run