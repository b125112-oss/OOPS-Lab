#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;
    double cgpa;

public:
    Student(string n, int a, int r, double c)
        : Person(n, a) {
        rollNo = r;
        cgpa = c;
    }
};

class Employee : virtual public Person {
protected:
    int employeeID;
    double salary;

public:
    Employee(string n, int a, int id, double s)
        : Person(n, a) {
        employeeID = id;
        salary = s;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n, int a,
                      int r, double c,
                      int id, double s)
        : Person(n, a),
          Student(n, a, r, c),
          Employee(n, a, id, s) {}

    void display() {
        cout << "\nTeaching Assistant Details";
        cout << "\nName       : " << name;
        cout << "\nAge        : " << age;
        cout << "\nRoll No    : " << rollNo;
        cout << "\nCGPA       : " << cgpa;
        cout << "\nEmployee ID: " << employeeID;
        cout << "\nSalary     : " << salary << endl;
    }
};

int main() {
    string name;
    int age, rollNo, employeeID;
    double cgpa, salary;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter roll number: ";
    cin >> rollNo;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    cout << "Enter employee ID: ";
    cin >> employeeID;

    cout << "Enter salary: ";
    cin >> salary;

    TeachingAssistant ta(
        name, age,
        rollNo, cgpa,
        employeeID, salary
    );

    ta.display();

    return 0;
}