#include "Store.h"

Store::Store() : sDept("shoes"), tDept("toys") {}

Dept& Store::shoes() { return sDept; }

Dept& Store::toys() { return tDept; }

Product* Store::search(string name) {
    Product* p = sDept.find(name);
    if (p != nullptr) return p;
    return tDept.find(name);
}