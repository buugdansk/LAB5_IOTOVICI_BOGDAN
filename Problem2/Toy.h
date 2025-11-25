#ifndef TOY_H
#define TOY_H

#include "Product.h"

class Toy : public Product {
public:
    Toy(string n, double p);
    void display() const override;
};

#endif