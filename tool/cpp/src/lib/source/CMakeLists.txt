add_library(libsource STATIC
    source.cpp platform.cpp
    package.cpp version.cpp)

target_include_directories(libsource PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
