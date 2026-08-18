#include <iostream>
#include <string>
using namespace std;

class SecuritySystem; // forward declaration

class Door {
private:
    int doorNumber;
    bool isLocked;

public:
    Door(int dn, bool locked) : doorNumber(dn), isLocked(locked) {}

    // SecuritySystem can access Door's private members
    friend class SecuritySystem;
};

class SecuritySystem {
public:
    void checkLockStatus(Door d) {
        cout << "Door Number: " << d.doorNumber << endl;
        cout << "Status: " << (d.isLocked ? "Locked" : "Unlocked") << endl;
    }
};

int main() {
    int doorNum1, doorNum2;
    char lockChoice1, lockChoice2;
    bool locked1, locked2;

    cout << "--- Enter Door 1 Details ---" << endl;
    cout << "Enter Door Number: ";
    cin >> doorNum1;
    cout << "Is the door locked? (y/n): ";
    cin >> lockChoice1;
    locked1 = (lockChoice1 == 'y' || lockChoice1 == 'Y');

    cout << "\n--- Enter Door 2 Details ---" << endl;
    cout << "Enter Door Number: ";
    cin >> doorNum2;
    cout << "Is the door locked? (y/n): ";
    cin >> lockChoice2;
    locked2 = (lockChoice2 == 'y' || lockChoice2 == 'Y');

    Door d1(doorNum1, locked1);
    Door d2(doorNum2, locked2);
    SecuritySystem security;

    security.checkLockStatus(d1);
    cout << endl;
    security.checkLockStatus(d2);
    return 0;
}