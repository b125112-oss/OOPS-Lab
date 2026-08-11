#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empId;
    string empName;
    float salary;

public:
    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin >> empName;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayDetails() {
        cout << empId << "\t" << empName << "\t" << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* emp = new Employee[n];  // Dynamically allocate array of objects

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        emp[i].acceptDetails();
    }

    cout << "\n--- Employee Details ---" << endl;
    cout << "ID\tName\tSalary" << endl;
    for (int i = 0; i < n; i++) {
        emp[i].displayDetails();
    }

    delete[] emp;   // Release the allocated array of objects
    emp = nullptr;

    return 0;
}