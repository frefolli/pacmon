#!/bin/bash

configureArchitecture() {
    inputArch="$1"
    buildForArchitecture="amd64"
    if [ ! -z "$inputArch" ]; then
        buildForArchitecture=$inputArch
    fi
}

configureToolchain() {
    if [ "$buildForArchitecture" == "i386" ]; then
        export CFLAGS="-m32 -O3"
        export CXXFLAGS="-m32 -O3"
        export LDFLAGS="-m32"
        export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"
    elif [ "$buildForArchitecture" == "amd64" ]; then
        export CFLAGS="-m64 -O3"
        export CXXFLAGS="-m64 -O3"
        export LDFLAGS="-m64"
        export PKG_CONFIG_PATH="/usr/lib64/pkgconfig"
    else
        echo -e "select a valid architecture = { i386 | amd64 }"
        exit 1
    fi
}

configureConcurrency() {
    buildJobs=1
    if [ "$(nproc --ignore=1)" -gt "$buildJobs" ]; then
        buildJobs="$(nproc --ignore=1)"
    fi
}

configureGenerator() {
    generator="make"
    if [ ! -z "$(which ninja)" ]; then
        cmake_flags="$cmake_flags -GNinja"
        generator="ninja"
    fi
    generator_flags=""
    if [ ! -z "$buildJobs" ]; then
        if [ "$buildJobs" -gt "1" ]; then
            generator_flags="$generator_flags -j$buildJobs"
        fi
    fi
}

configureCompiler() {
   if [ ! -z "$(which clang++)" ]; then
        cmake_flags="$cmake_flags -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang"
    fi
}

configureCMake() {
    cmake_flags="-Bbuild -DCMAKE_BUILD_TYPE=Release"
}

configure() {
    configureArchitecture $1
    configureCMake
    configureToolchain
    configureConcurrency
    configureGenerator
    configureCompiler

}

build() {
    cmake $cmake_flags && $generator -C build $generator_flags
}

main() {
    configure $1 && build
}

main $1
