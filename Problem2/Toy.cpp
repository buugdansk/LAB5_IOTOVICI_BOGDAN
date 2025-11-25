#include "Toy.h"

Toy::Toy(string n, double p) : Product(n, p) {}

void Toy::display() const {
    cout << "[toy]  " << name << " | price: $" << price << endl;
}