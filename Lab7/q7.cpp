#include <iostream>
using namespace std;

class Date {
    int day, month, year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    bool operator==(Date d) {
        return day == d.day &&
               month == d.month &&
               year == d.year;
    }
};

int main() {
    Date d1(15, 8, 2026);
    Date d2(15, 8, 2026);

    if (d1 == d2)
        cout << "Both dates are equal." << endl;
    else
        cout << "Dates are not equal." << endl;

    return 0;
}