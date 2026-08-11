#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    float price;
    int quantity;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cout << "Enter Product Name: ";
        cin >> productName;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << productId << "\t" << productName << "\t"
             << price << "\t" << quantity << endl;
    }

    float getCost() const {
        return price * quantity;
    }
};

int main() {
    int n;
    cout << "Enter number of products in the cart: ";
    cin >> n;

    Product* cart = new Product[n];  // dynamically allocate array of products

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Product " << i + 1 << ":" << endl;
        cart[i].acceptDetails();
    }

    cout << "\n--- Shopping Cart ---" << endl;
    cout << "ID\tName\tPrice\tQty" << endl;
    float totalCost = 0;
    for (int i = 0; i < n; i++) {
        cart[i].displayDetails();
        totalCost += cart[i].getCost();
    }

    cout << "\nTotal amount: " << totalCost << endl;

    delete[] cart;   // release the dynamically allocated memory
    cart = nullptr;

    return 0;
}