#!/bin/bash
BOVISA_PATH="/var/lib/docker/volumes/bovisa-debian64/_data/"

setup() {
    sudo docker volume create bovisa-debian64
    sudo cp bovisa/* -r $BOVISA_PATH
}

run() {
    sudo docker run -t -i --mount source=bovisa-debian64,destination=/bovisa-debian64 ubuntu:latest bash /bovisa-debian64/PKGBUILD
    sudo cp $BOVISA_PATH -r output
    sudo chown refo output
}

cleanup() {
    sudo docker volume rm bovisa-debian64
}

setup
run
cleanup
