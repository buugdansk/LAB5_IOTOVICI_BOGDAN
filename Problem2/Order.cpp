#include "Order.h"

Order::Order(int orderId) : id(orderId) {}

void Order::add(Product* p) {
    items.push_back(p);
}

const vector<Product*>& Order::getItems() const {
    return items;
}

int Order::getId() const {
    return id;
}

double Order::getTotal() const {
    double total = 0;
    for (int i = 0; i < items.size(); ++i) {
        total += items[i]->getPrice();
    }
    return total;
}