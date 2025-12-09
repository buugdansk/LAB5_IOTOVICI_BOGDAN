#include <iostream>
#include "Department.h"
#include "Order.h"
#include "Shoe.h"
#include "Toy.h"

using namespace std;

int main() {
    Department store("The Store");

    // add
    store.addProduct(new Shoe("Nike", 100.0));
    store.addProduct(new Toy("Lego", 50.0));
    store.addProduct(new Shoe("Puma", 120.0));
    store.addProduct(new Toy("Blocks", 70.0));
    store.addProduct(new Shoe("Airforce1", 200.0));
    store.addProduct(new Toy("Doll", 10.0));

    store.showInventory();
    // find
    string searchName;
    cout << "task 2 search: ";
    getline(cin, searchName); 

    if (store.findProduct(searchName) != nullptr) {
        cout << "product found" << endl;
    } else {
        cout << "not found" << endl;
    }
    
    // remove
    string removeName;
    cout << "task 3 remove: ";
    getline(cin, removeName);

    if (store.removeProduct(removeName)) {
        cout << "product removed" << endl;
        store.showInventory(); 
    } else {
        cout << "product not found" << endl;
    }
    // sort
    cout << "Sorting inventory by name and then by price" << endl;
    store.sortByName();
    store.showInventory();
    store.sortByPrice();
    store.showInventory();
    // order/receipt
    Order order;
    order.addToOrder(store.findProduct("Lego"));
    order.addToOrder(store.findProduct("Blocks"));
    order.printReceipt();
    // check
    string checkName;
    cout << "task 6 check: ";
    getline(cin, checkName);

    if (order.hasProduct(checkName)) {
        cout << "Item in order." << endl;
    } else {
        cout << "Item not in order." << endl;
    }
}