#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "Product.h"

class Order {
private:
    std::vector<Product*> cart; 

public:
    Order();
    
    void addToOrder(Product* p);
    void printReceipt();
    void clearOrder();
    bool hasProduct(string name);
};

#endif