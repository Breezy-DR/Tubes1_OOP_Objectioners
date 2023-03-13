#include "ValueHolder.hpp"

ValueHolder::ValueHolder() {
    this->val = 0;
}

ValueHolder::ValueHolder(int _val) {
    this->val = _val;
}

ValueHolder::ValueHolder(const ValueHolder& vh) {
    this->val = vh.val;
}

ValueHolder::~ValueHolder() {}

int ValueHolder::value() {
    return this->val;
}