#include<lib/exceptions/invalid_source_platform_index_file_path.hpp>

lib::exceptions::InvalidSourcePlatformIndexFilePath::InvalidSourcePlatformIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("source platform", indexFilePath) {}