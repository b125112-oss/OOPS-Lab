#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double basicSalary;

public:
    Employee(string n, double salary) {
        name = n;
        basicSalary = salary;
    }
};

class Developer : public Employee {
protected:
    int experience;

public:
    Developer(string n, double salary, int exp)
        : Employee(n, salary) {
        experience = exp;
    }
};

class SeniorDeveloper : public Developer {
private:
    double projectBonus;

public:
    SeniorDeveloper(string n, double salary, int exp, double bonus)
        : Developer(n, salary, exp) {
        projectBonus = bonus;
    }

    void displaySalary() {
        double experienceBonus = 0.05 * basicSalary * experience;
        double finalSalary = basicSalary + experienceBonus + projectBonus;

        cout << "\nEmployee Name   : " << name;
        cout << "\nBasic Salary    : " << basicSalary;
        cout << "\nExperience      : " << experience << " years";
        cout << "\nExperience Bonus: " << experienceBonus;
        cout << "\nProject Bonus   : " << projectBonus;
        cout << "\nFinal Salary    : " << finalSalary << endl;
    }
};

int main() {
    string name;
    double basicSalary, projectBonus;
    int experience;

    cout << "Enter employee name: ";
    getline(cin, name);

    cout << "Enter basic salary: ";
    cin >> basicSalary;

    cout << "Enter experience (years): ";
    cin >> experience;

    cout << "Enter project bonus: ";
    cin >> projectBonus;

    SeniorDeveloper obj(name, basicSalary, experience, projectBonus);

    obj.displaySalary();

    return 0;
}