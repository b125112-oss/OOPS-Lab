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

        cout << "Person constructor executed." << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;
    double salary;

public:
    Employee(string n, int a, int id, double s)
        : Person(n, a) {
        employeeID = id;
        salary = s;

        cout << "Employee constructor executed." << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id,
            double s, string dept)
        : Employee(n, a, id, s) {
        department = dept;

        cout << "Manager constructor executed." << endl;
    }

    void display() {
        cout << "\nManager Details";
        cout << "\nName       : " << name;
        cout << "\nAge        : " << age;
        cout << "\nEmployee ID: " << employeeID;
        cout << "\nSalary     : " << salary;
        cout << "\nDepartment : " << department << endl;
    }
};

int main() {
    string name, department;
    int age, employeeID;
    double salary;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter employee ID: ";
    cin >> employeeID;

    cout << "Enter salary: ";
    cin >> salary;

    cin.ignore();

    cout << "Enter department: ";
    getline(cin, department);

    cout << "\nCreating Manager object...\n\n";

    Manager obj(
        name,
        age,
        employeeID,
        salary,
        department
    );

    cout << endl;
    obj.display();

    return 0;
}