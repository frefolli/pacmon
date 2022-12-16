#include<lib/exceptions/item_already_there.hpp>

lib::exceptions::ItemAlreadyThere::ItemAlreadyThere(std::string context, std::string item)
: std::runtime_error(context + ": " + item + " already there") {
    this->context = context;
}

std::string lib::exceptions::ItemAlreadyThere::getContext() {
    return this->context;
}

std::string lib::exceptions::ItemAlreadyThere::getItem() {
    return this->item;
}