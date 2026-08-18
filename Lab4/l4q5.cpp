#include <iostream>
#include <string>
using namespace std;

class FoodOrder {
private:
    int orderId;
    string foodItem;
    int quantity;
    double price;

public:
    FoodOrder(int id, string item, int qty, double p)
        : orderId(id), foodItem(item), quantity(qty), price(p) {}

    friend void calculateBill(FoodOrder f);
};

// Friend function accessing private members of FoodOrder
void calculateBill(FoodOrder f) {
    double total = f.quantity * f.price;

    cout << "----- Order Details -----" << endl;
    cout << "Order ID  : " << f.orderId << endl;
    cout << "Food Item : " << f.foodItem << endl;
    cout << "Quantity  : " << f.quantity << endl;
    cout << "Price     : Rs. " << f.price << " each" << endl;
    cout << "Total Bill: Rs. " << total << endl;
}

int main() {
    int orderId, quantity;
    string foodItem;
    double price;

    cout << "Enter Order ID: ";
    cin >> orderId;
    cin.ignore();

    cout << "Enter Food Item: ";
    getline(cin, foodItem);

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Price per item: ";
    cin >> price;

    FoodOrder order(orderId, foodItem, quantity, price);
    calculateBill(order);
    return 0;
}