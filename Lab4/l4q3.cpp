#include <iostream>
#include <string>
using namespace std;

class ParkingSlot {
private:
    int slotNumber;
    string vehicleNumber;
    bool isOccupied;

public:
    ParkingSlot(int sn, string vn, bool occ)
        : slotNumber(sn), vehicleNumber(vn), isOccupied(occ) {}

    friend void checkSlot(ParkingSlot p);
};

// Friend function accessing private members of ParkingSlot
void checkSlot(ParkingSlot p) {
    cout << "Slot Number: " << p.slotNumber << endl;
    if (p.isOccupied) {
        cout << "Status: Occupied" << endl;
        cout << "Vehicle Number: " << p.vehicleNumber << endl;
    } else {
        cout << "Status: Available" << endl;
    }
}

int main() {
    int slotNum1, slotNum2;
    string vehicleNum1, vehicleNum2;
    char occupiedChoice1, occupiedChoice2;
    bool occupied1, occupied2;

    cout << "--- Enter Parking Slot 1 Details ---" << endl;
    cout << "Enter Slot Number: ";
    cin >> slotNum1;
    cout << "Is the slot occupied? (y/n): ";
    cin >> occupiedChoice1;
    occupied1 = (occupiedChoice1 == 'y' || occupiedChoice1 == 'Y');
    cin.ignore();
    if (occupied1) {
        cout << "Enter Vehicle Number: ";
        getline(cin, vehicleNum1);
    } else {
        vehicleNum1 = "";
    }

    cout << "\n--- Enter Parking Slot 2 Details ---" << endl;
    cout << "Enter Slot Number: ";
    cin >> slotNum2;
    cout << "Is the slot occupied? (y/n): ";
    cin >> occupiedChoice2;
    occupied2 = (occupiedChoice2 == 'y' || occupiedChoice2 == 'Y');
    cin.ignore();
    if (occupied2) {
        cout << "Enter Vehicle Number: ";
        getline(cin, vehicleNum2);
    } else {
        vehicleNum2 = "";
    }

    ParkingSlot p1(slotNum1, vehicleNum1, occupied1);
    ParkingSlot p2(slotNum2, vehicleNum2, occupied2);

    checkSlot(p1);
    cout << endl;
    checkSlot(p2);
    return 0;
}