#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    float salary, hra, da, grossSalary;

public:
    void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> salary;
    }

    void calculate()
    {
        hra = 0.20 * salary;
        da = 0.10 * salary;
        grossSalary = salary + hra + da;
    }

    void display()
    {
        cout << "\nEmployee Details\n" << endl;
        cout << "Employee ID   : " << empId << endl;
        cout << "Name          : " << name << endl;
        cout << "Basic Salary  : " << salary << endl;
        cout << "HRA (20%)     : " << hra << endl;
        cout << "DA (10%)      : " << da << endl;
        cout << "Gross Salary  : " << grossSalary << endl;
    }
};

int main()
{
    Employee e;

    e.accept();
    e.calculate();
    e.display();

    return 0;
}