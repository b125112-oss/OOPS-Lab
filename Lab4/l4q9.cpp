#include <iostream>
#include <string>
using namespace std;

class Result; // forward declaration

class Exam {
private:
    string studentName;
    string subject;
    double marks;
    double maxMarks;

public:
    Exam(string sn, string sub, double m, double mm)
        : studentName(sn), subject(sub), marks(m), maxMarks(mm) {}

    // Result can access Exam's private members
    friend class Result;
};

class Result {
public:
    void showResult(Exam e) {
        double percentage = (e.marks / e.maxMarks) * 100;

        cout << "Student Name: " << e.studentName << endl;
        cout << "Subject     : " << e.subject << endl;
        cout << "Marks       : " << e.marks << " / " << e.maxMarks << endl;
        cout << "Percentage  : " << percentage << "%" << endl;
        cout << "Result      : " << (percentage >= 40 ? "Pass" : "Fail") << endl;
    }
};

int main() {
    string studentName, subject;
    double marks, maxMarks;

    cout << "Enter Student Name: ";
    getline(cin, studentName);
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Marks Obtained: ";
    cin >> marks;
    cout << "Enter Maximum Marks: ";
    cin >> maxMarks;

    Exam e1(studentName, subject, marks, maxMarks);
    Result r;
    r.showResult(e1);
    return 0;
}