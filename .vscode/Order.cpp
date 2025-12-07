#include "Order.h"
#include <iomanip> // for std::setprecision and std::fixed

using namespace std;

Order::Order() {
    
}

void Order::addToOrder(Product* p) {
    cart.push_back(p);
}

void Order::printReceipt() {
    double total = 0.0;
    cout << "- Receipt -" << endl;
    for (Product* p : cart) {
        p->displayInfo();
        total += p->getPrice();
    }
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
}

void Order::clearOrder() {
    cart.clear();
}

bool Order::hasProduct(string name) {
    for (Product* p : cart) {
        if (p->getName() == name) {
            return true;
        }
    }
    return false;
}