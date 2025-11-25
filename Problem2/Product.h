#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p);
    virtual ~Product();

    string getName() const;
    double getPrice() const;

    virtual void display() const;
};

#endif