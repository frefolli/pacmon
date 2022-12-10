add_library(libtypes STATIC semver.cpp)
target_include_directories(libtypes PUBLIC ${CMAKE_SOURCE_DIR}/include)
