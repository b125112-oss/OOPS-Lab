#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string brand;
    string model;
    int batteryPercentage;

public:
    Mobile(string b, string m, int bp)
        : brand(b), model(m), batteryPercentage(bp) {}

    friend void checkBattery(Mobile m);
};

// Friend function accessing private members of Mobile
void checkBattery(Mobile m) {
    cout << "----- Mobile Details -----" << endl;
    cout << "Brand   : " << m.brand << endl;
    cout << "Model   : " << m.model << endl;
    cout << "Battery : " << m.batteryPercentage << "%" << endl;

    if (m.batteryPercentage < 20)
        cout << "Battery Low" << endl;
    else
        cout << "Battery Normal" << endl;
}

int main() {
    string brand1, model1, brand2, model2;
    int battery1, battery2;

    cout << "--- Enter Mobile 1 Details ---" << endl;
    cout << "Enter Brand: ";
    getline(cin, brand1);
    cout << "Enter Model: ";
    getline(cin, model1);
    cout << "Enter Battery Percentage: ";
    cin >> battery1;
    cin.ignore();

    cout << "\n--- Enter Mobile 2 Details ---" << endl;
    cout << "Enter Brand: ";
    getline(cin, brand2);
    cout << "Enter Model: ";
    getline(cin, model2);
    cout << "Enter Battery Percentage: ";
    cin >> battery2;
    cin.ignore();

    Mobile m1(brand1, model1, battery1);
    Mobile m2(brand2, model2, battery2);

    checkBattery(m1);
    cout << endl;
    checkBattery(m2);
    return 0;
}