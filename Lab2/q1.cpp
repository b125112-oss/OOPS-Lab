#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    float marks;

public:
    void accept()
    {
        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks in one subject: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\nStudent Details" << endl;
        cout << "Roll Number : " << roll << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : " << marks << endl;
    }
};

int main()
{
    Student s;

    s.accept();
    s.display();

    return 0;
}