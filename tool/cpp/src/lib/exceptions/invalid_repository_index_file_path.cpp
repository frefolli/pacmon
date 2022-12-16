#include<lib/exceptions/invalid_repository_index_file_path.hpp>

lib::exceptions::InvalidRepositoryIndexFilePath::InvalidRepositoryIndexFilePath(std::string indexFilePath)
 : lib::exceptions::InvalidIndexFilePath("repository", indexFilePath) {}