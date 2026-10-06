#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    int rentalDays;

public:
    Vehicle(string reg, int days) {
        registrationNumber = reg;
        rentalDays = days;
    }
};

class Car : public Vehicle {
protected:
    double dailyRate;

public:
    Car(string reg, int days, double rate)
        : Vehicle(reg, days) {
        dailyRate = rate;
    }
};

class LuxuryCar : public Car {
private:
    double luxuryCharge;

public:
    LuxuryCar(string reg, int days, double rate, double charge)
        : Car(reg, days, rate) {
        luxuryCharge = charge;
    }

    void displayCost() {
        double totalCost = (dailyRate + luxuryCharge) * rentalDays;

        cout << "\nRegistration Number: " << registrationNumber;
        cout << "\nRental Days       : " << rentalDays;
        cout << "\nDaily Rate        : " << dailyRate;
        cout << "\nLuxury Charge/Day : " << luxuryCharge;
        cout << "\nTotal Rental Cost : " << totalCost << endl;
    }
};

int main() {
    string registrationNumber;
    int rentalDays;
    double dailyRate, luxuryCharge;

    cout << "Enter registration number: ";
    cin >> registrationNumber;

    cout << "Enter number of rental days: ";
    cin >> rentalDays;

    cout << "Enter daily rental rate: ";
    cin >> dailyRate;

    cout << "Enter luxury charge per day: ";
    cin >> luxuryCharge;

    LuxuryCar car(
        registrationNumber,
        rentalDays,
        dailyRate,
        luxuryCharge
    );

    car.displayCost();

    return 0;
}