#ifndef TOOL_LIB_EXCEPTIONS_INVALID_INDEX_FILE_PATH
#define TOOL_LIB_EXCEPTIONS_INVALID_INDEX_FILE_PATH

#include<string>
#include<stdexcept>

namespace lib::exceptions {
    class InvalidIndexFilePath : public std::runtime_error {
        private:
            std::string context;
            std::string indexFilePath;
        
        public:
            InvalidIndexFilePath(std::string context, std::string indexFilePath);
            std::string getContext();
            std::string getIndexFilePath();
    };
}

#endif
