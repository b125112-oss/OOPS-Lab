#include <iostream>
#include <string>
using namespace std;

class HomeController; // forward declaration

class SmartDevice {
private:
    string deviceName;
    string deviceType;
    bool powerStatus; // true = ON, false = OFF

public:
    SmartDevice(string dn, string dt, bool ps)
        : deviceName(dn), deviceType(dt), powerStatus(ps) {}

    // HomeController can access and modify SmartDevice's private members
    friend class HomeController;
};

class HomeController {
public:
    void displayInfo(SmartDevice d) {
        cout << "Device Name: " << d.deviceName << endl;
        cout << "Device Type: " << d.deviceType << endl;
    }

    void turnOn(SmartDevice &d) {
        d.powerStatus = true;
        cout << d.deviceName << " turned ON." << endl;
    }

    void turnOff(SmartDevice &d) {
        d.powerStatus = false;
        cout << d.deviceName << " turned OFF." << endl;
    }

    void showStatus(SmartDevice d) {
        cout << "Power Status: " << (d.powerStatus ? "ON" : "OFF") << endl;
    }
};

int main() {
    string deviceName, deviceType;
    char statusChoice;
    bool powerStatus;

    cout << "Enter Device Name: ";
    getline(cin, deviceName);
    cout << "Enter Device Type: ";
    getline(cin, deviceType);
    cout << "Enter Initial Power Status (y = ON, n = OFF): ";
    cin >> statusChoice;
    powerStatus = (statusChoice == 'y' || statusChoice == 'Y');

    SmartDevice light(deviceName, deviceType, powerStatus);
    HomeController controller;

    controller.displayInfo(light);
    controller.showStatus(light);
    controller.turnOn(light);
    controller.showStatus(light);
    controller.turnOff(light);
    controller.showStatus(light);
    return 0;
}