#include<lib/exceptions/invalid_repository_version_index_file_path.hpp>

lib::exceptions::InvalidRepositoryVersionIndexFilePath::InvalidRepositoryVersionIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("repository version", indexFilePath) {}