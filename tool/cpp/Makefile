@all: build/src/main/main

build/src/main/main: src
	sh ./build.sh

clean:
	rm -rf build dist

run: build/src/main/main
	./build/src/main/main
