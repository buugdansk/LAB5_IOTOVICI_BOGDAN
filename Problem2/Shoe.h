#ifndef SHOE_H
#define SHOE_H

#include "Product.h"

class Shoe : public Product {
public:
    Shoe(string n, double p);
    void display() const override;
};

#endif