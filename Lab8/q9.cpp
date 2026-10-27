#include <iostream>
#include <iomanip>
using namespace std;

class Robot {
public:
    virtual ~Robot() {}
    virtual void move(double distance) const {
        cout << "Generic robot moving " << distance << " m" << endl;
    }
};

class WheeledRobot : public Robot {
public:
    void move(double distance) const override {
        cout << "Wheeled Robot -> Distance: " << distance
             << " m, Speed: 2 m/s, Travel time: " << distance / 2.0 << " s" << endl;
    }
};

class TrackedRobot : public Robot {
public:
    void move(double distance) const override {
        cout << "Tracked Robot -> Distance: " << distance
             << " m, Speed: 1.2 m/s, Travel time: " << distance / 1.2 << " s" << endl;
    }
};

int main() {
    double distance;
    cout << "Enter distance to travel (m): ";
    cin >> distance;
    if (!cin || distance < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    Robot* robots[2];
    robots[0] = new WheeledRobot();
    robots[1] = new TrackedRobot();

    cout << fixed << setprecision(2) << endl;
    for (int i = 0; i < 2; i++)
        robots[i]->move(distance);     // runtime polymorphism

    for (int i = 0; i < 2; i++)
        delete robots[i];
    return 0;
}
