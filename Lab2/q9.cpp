#include <iostream>
#include <string>
using namespace std;

class StudentResult
{
    string name;
    int roll, marks[5], total;
    float percentage;
    char grade;

public:
    void input()
    {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Marks of 5 Subjects:\n";
        total = 0;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
    }

    void calculate()
    {
        percentage = total / 5.0;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    void display()
    {
        cout << "\n--- Student Result ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Total Marks: " << total << "/500" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    StudentResult s;

    s.input();
    s.calculate();
    s.display();

    return 0;
}