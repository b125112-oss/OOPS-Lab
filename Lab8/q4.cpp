#include <iostream>
#include <iomanip>
using namespace std;

class Delivery {
public:
    virtual ~Delivery() {}
    virtual double estimateTime(double distance) const { return 0.0; }   // minutes
};

class BikeDelivery : public Delivery {
public:
    double estimateTime(double distance) const override {
        return (distance / 20.0) * 60.0 + 5.0;   // +5 min traffic
    }
};

class DroneDelivery : public Delivery {
public:
    double estimateTime(double distance) const override {
        return (distance / 40.0) * 60.0 + 2.0;   // +2 min take-off/landing
    }
};

int main() {
    double distance;
    cout << "Enter delivery distance (km): ";
    cin >> distance;
    if (!cin || distance < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    BikeDelivery bike;
    DroneDelivery drone;
    Delivery* d1 = &bike;
    Delivery* d2 = &drone;

    cout << fixed << setprecision(2);
    cout << "\nBike delivery time  : " << d1->estimateTime(distance) << " minutes\n";
    cout << "Drone delivery time : " << d2->estimateTime(distance) << " minutes\n";
    return 0;
}
