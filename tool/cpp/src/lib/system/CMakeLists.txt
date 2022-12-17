add_library(libsystem STATIC
            file_manager.cpp software_manager.cpp)

target_include_directories(libsystem PUBLIC
                            ${CMAKE_SOURCE_DIR}/include)
