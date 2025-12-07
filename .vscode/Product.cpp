#include "Product.h"
#include <iostream> 
using namespace std; 

Product::Product(string n, double p) {
    name = n;
    price = p;
}

Product::~Product() {
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::displayInfo() const {
    cout << "Product: " << name << " | Price: $" << price << endl;
}