#!/bin/bash
# i assume you are using debian:bookworm x86_64
#
WANT_TO_CROSS_COMPILE="yes"
WANT_TO_USE_CLANG="yes"
WANT_TO_USE_NINJA="yes"

prepare_repository() {
    if [ $WANT_TO_CROSS_COMPILE == "yes" ]; then
        if [ -z "$(dpkg --print-foreign-architectures | grep i386)" ]; then
            sudo dpkg --add-architecture i386
            sudo apt update
        fi
    fi
    INSTALL_QUEUE=""
}

install_build_tools() {
    INSTALL_QUEUE="$INSTALL_QUEUE build-essential cmake"
    if [ $WANT_TO_USE_CLANG == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE clang"
    fi
    if [ $WANT_TO_USE_NINJA == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE ninja-build"
    fi
}

install_libraries() {
    INSTALL_QUEUE="$INSTALL_QUEUE libboost-all-dev:amd64 libyaml-cpp-dev:amd64"
    if [ $WANT_TO_CROSS_COMPILE == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE libboost-all-dev:i386 libyaml-cpp-dev:i386"
    fi
}

perform_install() {
    sudo apt install $INSTALL_QUEUE
}

if [ "$EUID" -eq 0 ]
  then echo "Please don't run this as root, i will call sudo for you"
  exit
fi

prepare_repository
install_build_tools
install_libraries
perform_install
