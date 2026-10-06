#include <iostream>
using namespace std;

class Academic {
protected:
    int mark1, mark2, mark3;

public:
    Academic(int m1, int m2, int m3) {
        mark1 = m1;
        mark2 = m2;
        mark3 = m3;
    }
};

class Sports {
protected:
    int sportsMark;

public:
    Sports(int sm) {
        sportsMark = sm;
    }
};

class StudentResult : public Academic, public Sports {
public:
    StudentResult(int m1, int m2, int m3, int sm)
        : Academic(m1, m2, m3), Sports(sm) {}

    void displayResult() {
        int total = mark1 + mark2 + mark3 + sportsMark;
        double average = total / 4.0;

        cout << "\nAcademic Mark 1 : " << mark1;
        cout << "\nAcademic Mark 2 : " << mark2;
        cout << "\nAcademic Mark 3 : " << mark3;
        cout << "\nSports Mark     : " << sportsMark;
        cout << "\nTotal           : " << total;
        cout << "\nAverage         : " << average << endl;
    }
};

int main() {
    int m1, m2, m3, sportsMark;

    cout << "Enter marks in Academic Subject 1: ";
    cin >> m1;

    cout << "Enter marks in Academic Subject 2: ";
    cin >> m2;

    cout << "Enter marks in Academic Subject 3: ";
    cin >> m3;

    cout << "Enter Sports marks: ";
    cin >> sportsMark;

    StudentResult result(m1, m2, m3, sportsMark);

    result.displayResult();

    return 0;
}