#ifndef TOOL_LIB_EXCEPTIONS_INDEX_OUT_OF_BOUND
#define TOOL_LIB_EXCEPTIONS_INDEX_OUT_OF_BOUND

#include<string>
#include<stdexcept>

namespace lib::exceptions {
    class IndexOutOfBound : public std::runtime_error {
        private:
            std::string context;
        
        public:
            IndexOutOfBound(std::string context);
            std::string getContext();
    };
}

#endif
