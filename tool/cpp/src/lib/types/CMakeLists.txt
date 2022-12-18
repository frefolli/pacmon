add_library(libtypes STATIC
    index_file.cpp semver.cpp
    semver_list.cpp string_list.cpp
    worker.cpp)
target_include_directories(libtypes PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
