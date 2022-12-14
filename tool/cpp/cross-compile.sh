#!/bin/bash
PACKAGE="tool"
VERSION="latest"
INSTALL_PATH="usr/local/bin"
SUCCESS=0
ERROR=1

buildForArchitecture() {
    arch=$1
    echo -e "[#] - building for $arch"
    bash build.sh $arch
    if [ -f build/src/main/main ]; then
        echo -e "[O] - built for $arch"
        return $SUCCESS
    else
        echo -e "[X] - error while building for $arch"
        return $ERROR
    fi
}

assemblePackageForArchitecture() {
    arch="$1"
    folder="$PACKAGE-$VERSION-$1"
    echo -e "[#] - packaging for $arch"
    mkdir -p $folder/$INSTALL_PATH
    cp build/src/main/main $folder/$INSTALL_PATH
    tar cfz $folder.tar.gz $folder
    echo -e "[O] - packaged for $arch"
    return $SUCCESS
}

cleanup() {
    rm -r build
    return $SUCCESS
}

workflowForArchitecture() {
    arch="$1"
    echo -e "[#] - running workflow for $arch"
    buildForArchitecture $arch && assemblePackageForArchitecture $arch && cleanup
    echo -e "[O] - ran workflow for $arch"
    return $SUCCESS
}

crossCompile() {
    echo -e "[#] - cross compiling"
    workflowForArchitecture i386
    workflowForArchitecture amd64
    echo -e "[O] - cross compiled"
}

crossCompile
