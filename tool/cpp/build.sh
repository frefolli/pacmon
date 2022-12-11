#!/bin/bash

# wantNinja="yes"
# wantClang="yes"
buildJobs=2

configure() {
    generator="make"
    cmake_flags="-Bbuild -DCMAKE_BUILD_TYPE=Release"
    if [ "$wantNinja" == "yes" ]; then
        cmake_flags="$cmake_flags -GNinja"
        generator="ninja"
    fi
    if [ "$wantClang" == "yes" ]; then
        cmake_flags="$cmake_flags -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang"
    fi

    ninja_flags=""
    if [ ! -z "$buildJobs" ]; then
        if [ "$buildJobs" -gt "1" ]; then
            ninja_flags="$ninja_flags -j$buildJobs"
        fi
    fi
}

build() {
    cmake $cmake_flags 
    $generator -C build $ninja_flags
}

package() {
    mkdir -p dist/usr/local/bin
    cp build/src/main/main dist/usr/local/bin
}

main() {
    configure
    build
    package
}

main
