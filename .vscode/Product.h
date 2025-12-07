#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>    // <--- REQUIRED for 'string'
#include <iostream>  // <--- REQUIRED for 'cout'
using namespace std; // <--- REQUIRED to use them without 'std::'

class Product {
protected:
    string name;
    double price;

    // Protected constructor: Only Shoe/Toy can use this
    Product(string n, double p);

public:
    ~Product(); 
    string getName() const;
    double getPrice() const;
    void displayInfo() const; 
};

#endif