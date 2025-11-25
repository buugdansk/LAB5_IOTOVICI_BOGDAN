#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}
    
    virtual ~Product() {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void display() const {
        cout << "product: " << name << " | price: $" << price;
    }
};

class Shoe : public Product {
public:
    Shoe(string n, double p) : Product(n, p) {}

    void display() const override {
        cout << "[shoe] " << name << " | price: $" << price << endl;
    }
};

class Toy : public Product {
public:
    Toy(string n, double p) : Product(n, p) {}

    void display() const override {
        cout << "[toy]  " << name << " | price: $" << price << endl;
    }
};

class Dept {
private:
    string name;
    vector<Product*> inv; 

public:
    Dept(string n) : name(n) {}

    ~Dept() {
        for (int i = 0; i < inv.size(); ++i) {
            delete inv[i];
        }
        inv.clear();
    }

    void add(Product* p) {
        inv.push_back(p);
        cout << "added to " << name << ": " << p->getName() << endl;
    }

    vector<Product*> getAll() const {
        return inv;
    }

    Product* find(string prodName) {
        for (int i = 0; i < inv.size(); ++i) {
            if (inv[i]->getName() == prodName) return inv[i];
        }
        return nullptr;
    }

    void remove(string prodName) {
        for (int i = 0; i < inv.size(); ++i) {
            if (inv[i]->getName() == prodName) {
                delete inv[i]; 
                inv.erase(inv.begin() + i);
                cout << "removed '" << prodName << "' from " << name << endl;
                return; 
            }
        }
    }

    void show() const {
        if (inv.empty()) {
            cout << "(empty)" << endl;
        } else {
            for (int i = 0; i < inv.size(); ++i) {
                inv[i]->display();
            }
        }
    }
};

class Order {
private:
    int id;
    vector<Product*> items; 
public:
    Order(int orderId) : id(orderId) {}

    void add(Product* p) {
        items.push_back(p);
    }

    const vector<Product*>& getItems() const { return items; }
    int getId() const { return id; }

    double getTotal() const {
        double total = 0;
        for (int i = 0; i < items.size(); ++i) {
            total += items[i]->getPrice();
        }
        return total;
    }
};

class Store {
private:
    Dept sDept;
    Dept tDept;

public:
    Store() : sDept("shoes"), tDept("toys") {}

    Dept& shoes() { return sDept; }
    
    Dept& toys() { return tDept; }

    Product* search(string name) {
        Product* p = sDept.find(name);
        if (p != nullptr) return p;
        return tDept.find(name);
    }
};

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

    int type; string name; double price;
    cin >> type >> name >> price;
    if (type == 1) {
        store.shoes().add(new Shoe(name, price));
    } else {
        store.toys().add(new Toy(name, price));
    }

    cin >> name;
    Product* p = store.search(name);
    if(p) {
        cout << "found: "; p->display();
    } else {
        cout << "not found: " << name << endl;
    }

    cin >> name;
    store.shoes().remove(name);
    store.toys().remove(name);

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
    
    for (int i = 0; i < allShoes.size(); ++i) {
        allShoes[i]->display();
    }
    for (int i = 0; i < allToys.size(); ++i) {
        allToys[i]->display();
    }

    Order newOrder(1);
    cin >> name; 
    Product* found = store.search(name);
    if (found) {
        newOrder.add(found);
        cout << "added '" << name << "' to order #1" << endl;
    }
    orders.push_back(newOrder);

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
    if(!inOrder) cout << "not found in orders" << endl;

    double grandTotal = 0;
    for (int i = 0; i < orders.size(); ++i) {
        grandTotal += orders[i].getTotal();
    }
    cout << "grand total revenue: $" << grandTotal << endl;

    return 0;
}