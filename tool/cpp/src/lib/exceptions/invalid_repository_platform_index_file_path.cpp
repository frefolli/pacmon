#include<lib/exceptions/invalid_repository_package_index_file_path.hpp>

lib::exceptions::InvalidRepositoryPackageIndexFilePath::InvalidRepositoryPackageIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("repository package", indexFilePath) {}