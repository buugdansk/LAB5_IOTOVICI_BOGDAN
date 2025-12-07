#include "Department.h"
#include <iostream>

using namespace std;
// CONSTRUCTOR
Department::Department(string n) {
    name = n;
}
// DESTRUCTOR
Department::~Department() {
    for (Product* p : inventory) {
        delete p;
    }
    inventory.clear();
}
// ADD PRODUCT
void Department::addProduct(Product* p) {
    inventory.push_back(p);
}
// SORTING

// helper functions for sorting
bool Department::compareName(Product* a, Product* b) {
    return a->getName() < b->getName(); 
}

bool Department::comparePrice(Product* a, Product* b) {
    return a->getPrice() < b->getPrice(); 
}

// sorting functions
void Department::sortByName() {
    sort(inventory.begin(), inventory.end(), compareName);
    cout << "Sorted by Name." << endl;
}

void Department::sortByPrice() {
    sort(inventory.begin(), inventory.end(), comparePrice);
    cout << "Sorted by Price." << endl;
}
// SHOW INVENTORY
void Department::showInventory() {
    if (inventory.empty()) {
        cout << "Empty" << endl;
    } else {
        for (Product* p : inventory) {
            cout << p->getName() << " ($" << p->getPrice() << ")" << endl;
        }
    }
    cout << endl;
}
// FIND PRODUCT
Product* Department::findProduct(string name) {
    for (Product* p : inventory) {
        if (p->getName() == name) {
            return p;
        }
    }
    return nullptr;
}
// REMOVE PRODUCT
bool Department::removeProduct(string name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;          
            inventory.erase(it); 
            return true;         
        }
    }
    return false; 
}