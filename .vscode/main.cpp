#include <iostream>
#include "Department.h"
#include "Order.h"
#include "Shoe.h"
#include "Toy.h"

using namespace std;

int main() {
    Department store("The Store");

    // --- TASK 1: ADD PRODUCTS ---
    store.addProduct(new Shoe("Nike", 100.0));
    store.addProduct(new Toy("Lego", 50.0));
    store.addProduct(new Shoe("Puma", 120.0));
    store.addProduct(new Toy("Blocks", 70.0));
    store.addProduct(new Shoe("Airforce1", 200.0));
    store.addProduct(new Toy("Doll", 10.0));

    store.showInventory();
    // --- TASK 2: FIND PRODUCT ---
    string searchName;
    cout << "task 2 search: ";
    getline(cin, searchName); 

    if (store.findProduct(searchName) != nullptr) {
        cout << "product found" << endl;
    } else {
        cout << "not found" << endl;
    }
    
    // --- TASK 3: REMOVE PRODUCT ---
    string removeName;
    cout << "task 3 remove: ";
    getline(cin, removeName);

    if (store.removeProduct(removeName)) {
        cout << "product removed" << endl;
        store.showInventory(); 
    } else {
        cout << "product not found" << endl;
    }
    // --- TASK 4: SORTING ---
    cout << "Sorting inventory by name and then by price" << endl;
    store.sortByName();
    store.showInventory();
    store.sortByPrice();
    store.showInventory();
    // --- TASK 5: ORDER/RECEIPT ---
    Order myOrder;
    myOrder.addToOrder(store.findProduct("Lego"));
    myOrder.addToOrder(store.findProduct("Blocks"));
    myOrder.printReceipt();
    // --- TASK 6: CHECK ITEM IN ORDER ---
    string checkName;
    cout << "task 6 check: ";
    getline(cin, checkName);

    if (myOrder.hasProduct(checkName)) {
        cout << "Item is in the order." << endl;
    } else {
        cout << "Item is not in the order." << endl;
    }
}