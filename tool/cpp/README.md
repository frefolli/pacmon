# tool cpp

## Dependencies

### Arch Linux

install the following packages with pacman or your AUR helper: `cmake yaml-cpp boost boost-libs`

### Debian Linux

install the following packages with apt or your wrapper: `cmake libyaml-cpp-dev libboost-all-dev`

## Build

```sh
mkdir build && cd build
cmake .. && cmake --build .
```

You will find the executable at this filepath: `build/src/main/main`

## Docker workflow

### Debian-like Enviroment

```bash
docker volume create bovisa
docker run -t -i --ip 0.0.0.0 -p 8080 --mount source=bovisa,destination=/mnt/bovisa bash
```

then from inside

```bash
apt update && apt install nala
nala install git clang cmake ninja-build build-essential libyaml-cpp-dev libboost-all-dev
git clone https://github.com/frefolli/pacmon
cd pacmon/tool/cpp
./build.sh && mkdir -p dist/usr/local/bin && cp build/src/main/main dist/usr/local/bin
tar cf dist.tar dist/
gzip dist.tar
cp dist.tar.gz /mnt/bovisa
```
