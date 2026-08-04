#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int id, quantity;
    string name;
    float price;

public:
    void accept()
    {
        cout << "Enter Product ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Available Quantity: ";
        cin >> quantity;

        cout << "Enter Price per Unit: ";
        cin >> price;
    }

    void updateQuantity()
    {
        int addQty;
        cout << "Enter quantity to add: ";
        cin >> addQty;

        quantity += addQty;
    }

    void display()
    {
        float totalInventory = quantity * price;

        cout << "\nProduct Details" << endl;
        cout << "------------------------" << endl;
        cout << "Product ID        : " << id << endl;
        cout << "Product Name      : " << name << endl;
        cout << "Available Quantity: " << quantity << endl;
        cout << "Price per Unit    : " << price << endl;
        cout << "Total Inventory   : " << totalInventory << endl;
    }
};

int main()
{
    Product p;

    p.accept();
    p.updateQuantity();
    p.display();

    return 0;
}