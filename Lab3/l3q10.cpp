#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empId;
    string empName;
    float basicSalary;
    int numMonths;
    float* monthlyEarnings;  // dynamically allocated array

public:
    Employee() : monthlyEarnings(nullptr), numMonths(0) {}

    ~Employee() {
        releaseMemory();
    }

    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin >> empName;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter number of months: ";
        cin >> numMonths;

        monthlyEarnings = new float[numMonths];  // allocate for the months
    }

    void acceptEarnings() {
        cout << "Enter monthly earnings for " << numMonths << " months:" << endl;
        for (int i = 0; i < numMonths; i++) {
            cin >> monthlyEarnings[i];
        }
    }

    float calculateTotal() const {
        float total = 0;
        for (int i = 0; i < numMonths; i++) {
            total += monthlyEarnings[i];
        }
        return total;
    }

    float calculateAverage() const {
        return calculateTotal() / numMonths;
    }

    int highestEarningMonth() const {
        int monthIndex = 0;
        for (int i = 1; i < numMonths; i++) {
            if (monthlyEarnings[i] > monthlyEarnings[monthIndex]) {
                monthIndex = i;
            }
        }
        return monthIndex + 1;  // 1-based month number
    }

    void displayAnalysis() const {
        cout << "\n--- Employee Salary Analysis ---" << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << empName << endl;
        cout << "Basic Salary: " << basicSalary << endl;

        cout << "Monthly Earnings: ";
        for (int i = 0; i < numMonths; i++) {
            cout << monthlyEarnings[i] << " ";
        }
        cout << endl;

        cout << "Total Earnings: " << calculateTotal() << endl;
        cout << "Average Monthly Earning: " << calculateAverage() << endl;
        cout << "Highest Earning Month: Month " << highestEarningMonth() << endl;
    }

    void releaseMemory() {
        delete[] monthlyEarnings;  // deallocate the earnings array
        monthlyEarnings = nullptr;
    }
};

int main() {
    Employee e;

    e.acceptDetails();
    e.acceptEarnings();
    e.displayAnalysis();
    e.releaseMemory();   // explicit release (destructor also handles it)

    return 0;
}