#include <iostream>
#include <algorithm>
#include <vector>
#include "Store.h"
#include "Shoe.h"
#include "Toy.h"
#include "Order.h"

using namespace std;

bool byName(Product* a, Product* b) {
    return a->getName() < b->getName();
}

bool byPrice(Product* a, Product* b) {
    return a->getPrice() < b->getPrice();
}

int main() {
    Store store;
    vector<Order> orders;

    store.shoes().add(new Shoe("nike", 100.0));
    store.toys().add(new Toy("lego", 50.0));

    // add
    int type; string name; double price;
    cin >> type >> name >> price;
    if (type == 1) {
        store.shoes().add(new Shoe(name, price));
    } else {
        store.toys().add(new Toy(name, price));
    }

    // find
    cin >> name;
    if (store.search(name) == true) {
        cout << "found" << endl;
    } else {
        cout << "not found: " << name << endl;
    }

    // remove
    cin >> name;
    store.shoes().remove(name);
    store.toys().remove(name);

    // sort
    int sortChoice;
    cin >> sortChoice;

    vector<Product*> allShoes = store.shoes().getAll();
    vector<Product*> allToys = store.toys().getAll();

    if (sortChoice == 1) {
        sort(allShoes.begin(), allShoes.end(), byName);
        sort(allToys.begin(), allToys.end(), byName);
    } else {
        sort(allShoes.begin(), allShoes.end(), byPrice);
        sort(allToys.begin(), allToys.end(), byPrice);
    }

    // display
    for (int i = 0; i < allShoes.size(); ++i) {
        allShoes[i]->display();
    }
    for (int i = 0; i < allToys.size(); ++i) {
        allToys[i]->display();
    }

    // order
    Order newOrder(1);
    cin >> name;
    
    Product* found = store.get(name);
    if (found != nullptr) {
        newOrder.add(found);
        cout << "added '" << name << "' to order #1" << endl;
    }
    orders.push_back(newOrder);

    // search order
    cin >> name;
    bool inOrder = false;
    for (int i = 0; i < orders.size(); ++i) {
        vector<Product*> currentItems = orders[i].getItems();
        for (int j = 0; j < currentItems.size(); ++j) {
            if (currentItems[j]->getName() == name) {
                cout << "found '" << name << "' in order id: " << orders[i].getId() << endl;
                inOrder = true;
            }
        }
    }
    if (!inOrder) cout << "order not found" << endl;

    // total
    double grandTotal = 0;
    for (int i = 0; i < orders.size(); ++i) {
        grandTotal += orders[i].getTotal();
    }
    cout << "total:" << grandTotal << endl;

    return 0;
}