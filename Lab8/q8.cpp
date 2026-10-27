#include <iostream>
#include <iomanip>
using namespace std;

class CloudResource {
public:
    virtual ~CloudResource() {}
    virtual double calculateCost(double cpuHours) const { return 0.0; }
};

class StandardInstance : public CloudResource {
public:
    double calculateCost(double cpuHours) const override {
        double cost = 5.0 * cpuHours;
        if (cpuHours > 100) cost *= 0.85;   // 15% discount
        return cost;
    }
};

class PremiumInstance : public CloudResource {
public:
    double calculateCost(double cpuHours) const override {
        double cost = 12.0 * cpuHours;
        if (cpuHours > 100) cost *= 0.85;   // 15% discount
        return cost;
    }
};

int main() {
    double hours;
    cout << "Enter CPU hours used: ";
    cin >> hours;
    if (!cin || hours < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    StandardInstance standard;
    PremiumInstance premium;
    CloudResource* r1 = &standard;
    CloudResource* r2 = &premium;

    cout << fixed << setprecision(2);
    cout << "\nStandard instance cost : Rs. " << r1->calculateCost(hours) << endl;
    cout << "Premium instance cost  : Rs. " << r2->calculateCost(hours) << endl;
    return 0;
}
