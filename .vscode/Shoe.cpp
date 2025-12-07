#include "Shoe.h"

Shoe::Shoe(string n, double p) : Product(n, p) {
    // This works because Shoe is a "child" and can access protected items
}

void Shoe::displayInfo() const {
    cout << "[SHOE] Style: " << name << " --- Cost: " << price << endl;
}