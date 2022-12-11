add_library(libtypes STATIC index_file.cpp semver.cpp)
target_include_directories(libtypes PUBLIC ${CMAKE_SOURCE_DIR}/include)
