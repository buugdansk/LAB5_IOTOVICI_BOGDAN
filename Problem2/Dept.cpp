#include "Dept.h"

Dept::Dept(string n) : name(n) {}

Dept::~Dept() {
    for (int i = 0; i < inv.size(); ++i) {
        delete inv[i];
    }
    inv.clear();
}

void Dept::add(Product* p) {
    inv.push_back(p);
    cout << "added to " << name << ": " << p->getName() << endl;
}

void Dept::remove(string prodName) {
    for (int i = 0; i < inv.size(); ++i) {
        if (inv[i]->getName() == prodName) {
            delete inv[i];
            inv.erase(inv.begin() + i);
            cout << "removed '" << prodName << "' from " << name << endl;
            return;
        }
    }
}

Product* Dept::get(string prodName) {
    for (int i = 0; i < inv.size(); ++i) {
        if (inv[i]->getName() == prodName) return inv[i];
    }
    return nullptr;
}

bool Dept::search(string prodName) {
    return get(prodName) != nullptr;
}

vector<Product*> Dept::getAll() const {
    return inv;
}

void Dept::show() const {
    if (inv.empty()) {
        cout << "(empty)" << endl;
    } else {
        for (int i = 0; i < inv.size(); ++i) {
            inv[i]->display();
        }
    }
}