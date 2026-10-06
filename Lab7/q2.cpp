#include <iostream>
#include <vector>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;
    vector<int> marks;

public:
    Student(string n, int r, vector<int> m) {
        name = n;
        rollNo = r;
        marks = m;
    }

    virtual void calculateResult() {
        int total = 0;

        for (int mark : marks)
            total += mark;

        cout << "Total Marks: " << total << endl;
    }

    virtual ~Student() {}
};

class RegularStudent : public Student {
public:
    RegularStudent(string n, int r, vector<int> m)
        : Student(n, r, m) {}

    void calculateResult() override {
        int total = 0;

        for (int mark : marks)
            total += mark;

        cout << "\nRegular Student";
        cout << "\nName       : " << name;
        cout << "\nRoll No    : " << rollNo;
        cout << "\nTotal Marks: " << total << endl;
    }
};

class ScholarshipStudent : public Student {
public:
    ScholarshipStudent(string n, int r, vector<int> m)
        : Student(n, r, m) {}

    void calculateResult() override {
        int total = 0;

        for (int mark : marks)
            total += mark;

        total += 5;

        cout << "\nScholarship Student";
        cout << "\nName       : " << name;
        cout << "\nRoll No    : " << rollNo;
        cout << "\nTotal Marks: " << total << " (including 5 bonus marks)" << endl;
    }
};

int main() {
    string name;
    int rollNo, n;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter roll number: ";
    cin >> rollNo;

    cout << "Enter number of subjects: ";
    cin >> n;

    vector<int> marks(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter marks of subject " << i + 1 << ": ";
        cin >> marks[i];
    }

    RegularStudent regular(name, rollNo, marks);
    ScholarshipStudent scholarship(name, rollNo, marks);

    regular.calculateResult();
    scholarship.calculateResult();

    return 0;
}