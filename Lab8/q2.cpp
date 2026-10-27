#include <iostream>
#include <iomanip>
using namespace std;

class ParkingSlot {
public:
    virtual ~ParkingSlot() {}
    virtual double calculateFee(int hours) const { return 0.0; }
};

class TwoWheelerSlot : public ParkingSlot {
public:
    double calculateFee(int hours) const override {
        double fee = 10.0 * hours;
        if (hours > 5) fee *= 0.90;   // 10% discount
        return fee;
    }
};

class FourWheelerSlot : public ParkingSlot {
public:
    double calculateFee(int hours) const override {
        double fee = 30.0 * hours;
        if (hours > 5) fee *= 0.90;   // 10% discount
        return fee;
    }
};

int main() {
    int hours;
    cout << "Enter number of hours parked: ";
    cin >> hours;
    if (!cin || hours < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    TwoWheelerSlot two;
    FourWheelerSlot four;
    ParkingSlot* p1 = &two;
    ParkingSlot* p2 = &four;

    cout << fixed << setprecision(2);
    cout << "\nTwo-wheeler fee  : Rs. " << p1->calculateFee(hours) << endl;
    cout << "Four-wheeler fee : Rs. " << p2->calculateFee(hours) << endl;
    return 0;
}
