#ifndef TOOL_LIB_EXCEPTIONS_INVALID_REPOSITORY_VERSION_INDEX_FILE_PATH
#define TOOL_LIB_EXCEPTIONS_INVALID_REPOSITORY_VERSION_INDEX_FILE_PATH

#include<string>
#include<stdexcept>
#include<lib/exceptions/invalid_index_file_path.hpp>

namespace lib::exceptions {
    class InvalidRepositoryVersionIndexFilePath : public InvalidIndexFilePath {
        public:
            InvalidRepositoryVersionIndexFilePath(std::string indexFilePath);
    };
}

#endif
