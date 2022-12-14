add_library(librepository STATIC
    repository.cpp platform.cpp
    package.cpp version.cpp)

target_include_directories(librepository PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
