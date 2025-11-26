#include "Store.h"

Store::Store() : sDept("shoes"), tDept("toys") {}

Dept& Store::shoes() { return sDept; }

Dept& Store::toys() { return tDept; }

Product* Store::get(string name) {
    Product* p = sDept.get(name);
    if (p != nullptr) return p;
    return tDept.get(name);
}

bool Store::search(string name) {
    return get(name) != nullptr;
}