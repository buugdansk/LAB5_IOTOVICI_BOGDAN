#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Product.h"

class Order {
private:
    int id;
    vector<Product*> items;

public:
    Order(int orderId);
    void add(Product* p);
    const vector<Product*>& getItems() const;
    int getId() const;
    double getTotal() const;
};

#endif