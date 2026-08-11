#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayDetails() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student* s = new Student();  // Dynamically allocate a Student object

    s->acceptDetails();   // -> operator used for dynamically allocated object
    s->displayDetails();

    delete s;             // Release the dynamically allocated object
    s = nullptr;

    return 0;
}