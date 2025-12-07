#include "Shoe.h"

Shoe::Shoe(string n, double p) : Product(n, p) {
    
}

void Shoe::displayInfo() const {
    cout << "Shoe: " << name << " --- Cost: " << price << endl;
}