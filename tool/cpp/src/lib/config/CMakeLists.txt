add_library(libconfig STATIC config.cpp)

target_include_directories(libconfig PUBLIC
                            ${CMAKE_SOURCE_DIR}/include)
