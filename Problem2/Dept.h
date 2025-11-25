#ifndef DEPT_H
#define DEPT_H

#include <vector>
#include "Product.h"

class Dept {
private:
    string name;
    vector<Product*> inv;

public:
    Dept(string n);
    ~Dept();

    void add(Product* p);
    void remove(string prodName);
    Product* find(string prodName);
    vector<Product*> getAll() const;
    void show() const;
};

#endif