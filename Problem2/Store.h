#ifndef STORE_H
#define STORE_H

#include "Dept.h"

class Store {
private:
    Dept sDept;
    Dept tDept;

public:
    Store();
    Dept& shoes();
    Dept& toys();
    
    bool search(string name);
    Product* get(string name);
};

#endif