#include <iostream>
#include <iomanip>
using namespace std;

class IrrigationSystem {
public:
    virtual ~IrrigationSystem() {}
    virtual double calculateWater(double moisture) const { return 0.0; }
};

class DripIrrigation : public IrrigationSystem {
public:
    double calculateWater(double moisture) const override { return 2.0 * (100.0 - moisture); }
};

class SprinklerIrrigation : public IrrigationSystem {
public:
    double calculateWater(double moisture) const override { return 3.0 * (100.0 - moisture); }
};

int main() {
    double moisture;
    cout << "Enter soil moisture (0-100 %): ";
    cin >> moisture;
    if (!cin || moisture < 0 || moisture > 100) {
        cout << "Invalid input. Moisture must be between 0 and 100.\n";
        return 1;
    }

    DripIrrigation drip;
    SprinklerIrrigation sprinkler;
    IrrigationSystem* s1 = &drip;
    IrrigationSystem* s2 = &sprinkler;

    cout << fixed << setprecision(2);
    cout << "\nDrip irrigation water      : " << s1->calculateWater(moisture) << " litres\n";
    cout << "Sprinkler irrigation water : " << s2->calculateWater(moisture) << " litres\n";
    return 0;
}
