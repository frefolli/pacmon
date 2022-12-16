#include<lib/exceptions/item_not_found.hpp>

lib::exceptions::ItemNotFound::ItemNotFound(std::string context, std::string item)
: std::runtime_error(context + ": " + item + " not found") {
    this->context = context;
}

std::string lib::exceptions::ItemNotFound::getContext() {
    return this->context;
}

std::string lib::exceptions::ItemNotFound::getItem() {
    return this->item;
}