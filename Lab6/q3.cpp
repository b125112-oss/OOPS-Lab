#include <iostream>
using namespace std;

class Student {
    string name;
    int marks;

public:
    Student(string n, int m) {
        name = n;
        marks = m;
    }

    bool operator>(Student s) {
        return marks > s.marks;
    }

    void display() {
        cout << name << " - " << marks << " marks" << endl;
    }

    string getName() {
        return name;
    }
};

int main() {
    Student s1("Rahul", 85);
    Student s2("Aman", 78);

    s1.display();
    s2.display();

    if (s1 > s2)
        cout << s1.getName() << " has higher marks." << endl;
    else
        cout << s2.getName() << " has higher marks." << endl;

    return 0;
}