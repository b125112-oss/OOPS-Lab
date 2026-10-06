#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeID;
    string name;

public:
    Employee(int id, string n) {
        employeeID = id;
        name = n;
    }
};

class Developer : virtual public Employee {
protected:
    string programmingLanguage;

public:
    Developer(int id, string n, string language)
        : Employee(id, n) {
        programmingLanguage = language;
    }
};

class Tester : virtual public Employee {
protected:
    string testingTool;

public:
    Tester(int id, string n, string tool)
        : Employee(id, n) {
        testingTool = tool;
    }
};

class TechLead : public Developer, public Tester {
public:
    TechLead(int id, string n,
             string language, string tool)
        : Employee(id, n),
          Developer(id, n, language),
          Tester(id, n, tool) {}

    void display() {
        cout << "\nTech Lead Details";
        cout << "\nEmployee ID          : " << employeeID;
        cout << "\nName                 : " << name;
        cout << "\nProgramming Language : " << programmingLanguage;
        cout << "\nTesting Tool         : " << testingTool << endl;
    }
};

int main() {
    int id;
    string name, language, tool;

    cout << "Enter employee ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter programming language: ";
    getline(cin, language);

    cout << "Enter testing tool: ";
    getline(cin, tool);

    TechLead obj(
        id,
        name,
        language,
        tool
    );

    obj.display();

    return 0;
}