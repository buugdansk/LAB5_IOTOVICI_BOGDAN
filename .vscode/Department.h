#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <string>
#include <algorithm> // <--- REQUIRED for sorting
#include "Product.h"

class Department {
private:
    std::string name;
    std::vector<Product*> inventory; 

public:
    Department(std::string n);
    ~Department(); 

    void addProduct(Product* p);
    void showInventory();
    Product* findProduct(std::string name);
    bool removeProduct(std::string name);

    void sortByName();
    void sortByPrice();

    static bool compareName(Product* a, Product* b);
    static bool comparePrice(Product* a, Product* b);
};

#endif