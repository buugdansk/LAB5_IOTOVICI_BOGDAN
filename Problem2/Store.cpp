#include "Store.h"

Store::Store() : sDept("shoes"), tDept("toys") {}

Dept& Store::shoes() { return sDept; }

Dept& Store::toys() { return tDept; }

bool Store::search(string name) {
    if (sDept.find(name)) return true;
    if (tDept.find(name)) return true;
    return false;
}

Product* Store::get(string name) {
    Product* p = sDept.get(name);
    if (p != nullptr) return p;
    return tDept.get(name);
}