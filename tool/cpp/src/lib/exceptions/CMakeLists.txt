add_library(libexceptions STATIC
    invalid_source_index_file_path.cpp invalid_repository_version_index_file_path.cpp
    index_out_of_bound.cpp invalid_source_package_index_file_path.cpp
    invalid_index_file_path.cpp invalid_source_platform_index_file_path.cpp
    invalid_repository_index_file_path.cpp invalid_source_version_index_file_path.cpp
    invalid_repository_package_index_file_path.cpp item_already_there.cpp
    invalid_repository_platform_index_file_path.cpp item_not_found.cpp)

target_include_directories(libexceptions PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
