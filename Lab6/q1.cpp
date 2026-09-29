#include <iostream>
using namespace std;

class Distance {
    int feet, inches;

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    Distance operator+(Distance d) {
        Distance temp;

        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet;

        if (temp.inches >= 12) {
            temp.feet += temp.inches / 12;
            temp.inches = temp.inches % 12;
        }

        return temp;
    }

    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 8);
    Distance d2(3, 7);

    Distance d3 = d1 + d2;

    cout << "Distance 1: ";
    d1.display();

    cout << "Distance 2: ";
    d2.display();

    cout << "Result: ";
    d3.display();

    return 0;
}