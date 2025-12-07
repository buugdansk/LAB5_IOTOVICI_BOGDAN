#include "Toy.h"

Toy::Toy(string n, double p) : Product(n, p) {
    // Constructor passes data to parent
}

void Toy::displayInfo() const {
    cout << "[TOY] Fun Item: " << name << " --- Cost: " << price << endl;
}