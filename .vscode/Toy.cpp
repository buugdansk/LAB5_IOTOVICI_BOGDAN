#include "Toy.h"

Toy::Toy(string n, double p) : Product(n, p) {
    
}

void Toy::displayInfo() const {
    cout << "Toy: " << name << " --- Cost: " << price << endl;
}