#ifndef TOOL_LIB_EXCEPTIONS_INVALID_WORKER_PATH
#define TOOL_LIB_EXCEPTIONS_INVALID_WORKER_PATH

#include<string>
#include<stdexcept>
#include<lib/exceptions/invalid_index_file_path.hpp>

namespace lib::exceptions {
    class InvalidWorkerPath : public InvalidIndexFilePath {
        public:
            InvalidWorkerPath(std::string path);
    };
}

#endif
