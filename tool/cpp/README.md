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
