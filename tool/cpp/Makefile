@all:

clean:
	rm -rf build

compile:
	cd build && cmake .. && cmake --build . && cd ..

build:
	mkdir build

build/src/main/main: build compile

run: build/src/main/main
	./build/src/main/main
