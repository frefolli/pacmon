#include<lib/exceptions/invalid_repository_platform_index_file_path.hpp>

lib::exceptions::InvalidRepositoryPlatformIndexFilePath::InvalidRepositoryPlatformIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("repository platform", indexFilePath) {}