add_library(libcli STATIC cli.cpp)

target_include_directories(libcli PUBLIC
                            ${CMAKE_SOURCE_DIR}/include)
