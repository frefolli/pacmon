#ifndef TOOL_LIB_EXCEPTIONS_ITEM_NOT_FOUND
#define TOOL_LIB_EXCEPTIONS_ITEM_NOT_FOUND

#include<string>
#include<stdexcept>

namespace lib::exceptions {
    class ItemNotFound : public std::runtime_error {
        private:
            std::string context;
            std::string item;
        
        public:
            ItemNotFound(std::string context, std::string item);
            std::string getContext();
            std::string getItem();
    };
}

#endif
