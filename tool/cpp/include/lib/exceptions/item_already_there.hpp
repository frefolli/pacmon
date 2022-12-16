#ifndef TOOL_LIB_EXCEPTIONS_ITEM_ALREADY_THERE
#define TOOL_LIB_EXCEPTIONS_ITEM_ALREADY_THERE

#include<string>
#include<stdexcept>

namespace lib::exceptions {
    class ItemAlreadyThere : public std::runtime_error {
        private:
            std::string context;
            std::string item;
        
        public:
            ItemAlreadyThere(std::string context, std::string item);
            std::string getContext();
            std::string getItem();
    };
}

#endif