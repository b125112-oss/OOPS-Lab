#include <iostream>
using namespace std;

class Product {
    string name;
    float price;
    int quantity;

public:
    Product(string n = "", float p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    Product operator+(Product p) {
        if (name == p.name && price == p.price) {
            return Product(name, price, quantity + p.quantity);
        }

        cout << "Products cannot be combined." << endl;
        return Product();
    }

    bool operator>(Product p) {
        return (price * quantity) > (p.price * p.quantity);
    }

    void display() {
        cout << "Product: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: " << price * quantity << endl;
    }
};

int main() {
    Product p1("Notebook", 50, 2);
    Product p2("Notebook", 50, 3);

    Product p3 = p1 + p2;

    cout << "Combined Product:" << endl;
    p3.display();

    Product p4("Pen", 20, 6);

    if (p3 > p4)
        cout << "\nCombined product has greater total value." << endl;
    else
        cout << "\nPen has greater or equal total value." << endl;

    return 0;
}