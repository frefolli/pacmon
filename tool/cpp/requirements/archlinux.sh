#!/bin/bash
# i assume you are using archlinux x86_64 an AUR_HELPER with pacman-linke semanthics

WANT_TO_CROSS_COMPILE="yes"
WANT_TO_USE_CLANG="yes"
WANT_TO_USE_NINJA="yes"
AUR_HELPER="yay"

prepare_repository() {
    if [ $WANT_TO_CROSS_COMPILE == "yes" ]; then
        if [ -z "$(pacman -Sl | grep -i lib32)" ]; then
            echo you need to uncomment multilib repository! - hit enter to edit pacman.conf
            read
            sudo vim /etc/pacman.conf
            sudo pacman -Syu
        fi
    fi
    INSTALL_QUEUE=""
}

install_build_tools() {
    INSTALL_QUEUE="$INSTALL_QUEUE base-devel cmake"
    if [ $WANT_TO_USE_CLANG == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE clang"
    fi
    if [ $WANT_TO_USE_NINJA == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE ninja"
    fi
}

install_libraries() {
    INSTALL_QUEUE="$INSTALL_QUEUE yaml-cpp boost-libs"
    if [ $WANT_TO_CROSS_COMPILE == "yes" ]; then
        INSTALL_QUEUE="$INSTALL_QUEUE lib32-yaml-cpp lib32-boost-libs"
    fi
}

perform_install() {
    $AUR_HELPER -Syu $INSTALL_QUEUE --needed
}

if [ "$EUID" -eq 0 ]
  then echo "Please don't run this as root, i will call sudo for you"
  exit
fi

prepare_repository
install_build_tools
install_libraries
perform_install
