cmake_minimum_required(VERSION 3.4)
project(tool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(yaml-cpp REQUIRED)
find_package(Boost REQUIRED)

add_subdirectory(src)
