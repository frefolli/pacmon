#include<lib/exceptions/index_out_of_bound.hpp>

lib::exceptions::IndexOutOfBound::IndexOutOfBound(std::string context)
: std::runtime_error(context + ": index out of bound") {
    this->context = context;
}

std::string lib::exceptions::IndexOutOfBound::getContext() {
    return this->context;
}