#include "Product.h"

Product::Product(string n, double p) : name(n), price(p) {}

Product::~Product() {}

string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

void Product::display() const {
    cout << "product: " << name << " | price: $" << price;
}