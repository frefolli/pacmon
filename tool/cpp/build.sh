#!/bin/bash
WANT_CLANG=no
WANT_NINJA=no
WANT_OPT=3

configureArchitecture() {
    inputArch="$1"
    buildForArchitecture="native"
    if [ ! -z "$inputArch" ]; then
        buildForArchitecture=$inputArch
    fi
}

configureToolchain() {
    if [ ! -z "$WANT_OPT" ]; then
        export CFLAGS="$CFLAGS -O$WANT_OPT"
        export CXXFLAGS="$CXXFLAGS -O$WANT_OPT"
    fi
    if [ "$buildForArchitecture" == "i386" ]; then
        export CFLAGS="$CFLAGS -m32"
        export CXXFLAGS="$CXXFLAGS -m32"
        export LDFLAGS="$LDFLAGS -m32"
        # export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"
    elif [ "$buildForArchitecture" == "amd64" ]; then
        export CFLAGS="$CFLAGS -m64"
        export CXXFLAGS="$CXXFLAGS -m64"
        export LDFLAGS="$LDFLAGS -m64"
        # export PKG_CONFIG_PATH="/usr/lib64/pkgconfig"
    elif [ ! "$buildForArchitecture" == "native" ]; then
        echo -e "select a valid architecture = { native | i386 | amd64 }"
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
    if [ "$WANT_NINJA" == "yes" ]; then
        if [ ! -z "$(which ninja)" ]; then
            cmake_flags="$cmake_flags -GNinja"
            generator="ninja"
        fi
    fi
    generator_flags=""
    if [ ! -z "$buildJobs" ]; then
        if [ "$buildJobs" -gt "1" ]; then
            generator_flags="$generator_flags -j$buildJobs"
        fi
    fi
}

configureCompiler() {
    if [ "$WANT_CLANG" == "yes" ]; then
        if [ ! -z "$(which clang++)" ]; then
            cmake_flags="$cmake_flags -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang"
        fi
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
