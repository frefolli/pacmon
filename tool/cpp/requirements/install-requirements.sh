#!/bin/bash

if [ -z "$(which pacman)" ]; then
    # archlinux
    return bash archlinux.sh
else
    echo -e "OS not supported, should be in list: { archlinux }"
    exit 1
