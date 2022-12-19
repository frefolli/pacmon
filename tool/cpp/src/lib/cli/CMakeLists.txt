add_library(libcli STATIC menu.cpp option.cpp)

target_include_directories(libcli PUBLIC
                            ${CMAKE_SOURCE_DIR}/include)
