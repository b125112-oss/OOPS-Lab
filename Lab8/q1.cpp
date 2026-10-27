#include <iostream>
using namespace std;

class Character {
public:
    virtual ~Character() {}
    virtual int attack() const { return 0; }
};

class Warrior : public Character {
    int strength;
public:
    explicit Warrior(int s) : strength(s) {}
    int attack() const override { return 20 + 2 * strength; }
};

class Archer : public Character {
    int agility;
public:
    explicit Archer(int a) : agility(a) {}
    int attack() const override { return 15 + 3 * agility; }
};

int main() {
    int strength, agility;
    cout << "Enter warrior strength: ";
    cin >> strength;
    cout << "Enter archer agility: ";
    cin >> agility;
    if (!cin || strength < 0 || agility < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    Warrior w(strength);
    Archer a(agility);
    Character* c1 = &w;
    Character* c2 = &a;

    cout << "\nWarrior damage (20 + 2 x " << strength << ") = " << c1->attack() << endl;
    cout << "Archer damage  (15 + 3 x " << agility << ") = " << c2->attack() << endl;
    return 0;
}
