add_library(libsource STATIC
            source.cpp platform.cpp
            package.cpp version.cpp
            source_worker.cpp platform_worker.cpp
            package_worker.cpp version_worker.cpp)

target_include_directories(libsource PUBLIC
                            ${CMAKE_SOURCE_DIR}/include)
