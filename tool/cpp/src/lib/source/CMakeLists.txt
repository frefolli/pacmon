add_library(libsource STATIC source.cpp)
target_include_directories(libsource PUBLIC ${CMAKE_SOURCE_DIR}/include)
