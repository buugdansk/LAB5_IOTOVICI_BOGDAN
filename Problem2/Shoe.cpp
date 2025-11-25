#include "Shoe.h"

Shoe::Shoe(string n, double p) : Product(n, p) {}

void Shoe::display() const {
    cout << "[shoe] " << name << " | price: $" << price << endl;
}