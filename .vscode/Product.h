#ifndef PRODUCT_H
#define PRODUCT_H

#include <string> 
#include <iostream> 
using namespace std; 

class Product {
protected:
    string name;
    double price;

    Product(string n, double p);

public:
    ~Product(); 
    string getName() const;
    double getPrice() const;
    void displayInfo() const; 
};

#endif