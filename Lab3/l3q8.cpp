#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    int numSubjects;
    float *marks; // dynamically allocated array of marks

public:
    // Constructor / destructor to be safe with memory
    Student()
    {
        marks = nullptr;
        numSubjects = 0;
    }

    ~Student()
    {
        releaseMarks();
    }

    void acceptDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Number of Subjects: ";
        cin >> numSubjects;

        allocateMarks();
    }

    void allocateMarks()
    {
        marks = new float[numSubjects]; // allocate marks array inside the class
    }

    void acceptMarks()
    {
        cout << "Enter marks for " << numSubjects << " subjects:" << endl;
        for (int i = 0; i < numSubjects; i++)
        {
            cin >> marks[i];
        }
    }

    float calculateTotal()
    {
        float total = 0;
        for (int i = 0; i < numSubjects; i++)
        {
            total += marks[i];
        }
        return total;
    }

    float calculateAverage()
    {
        return calculateTotal() / numSubjects;
    }

    void displayResult()
    {
        cout << "\n--- Student Result ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < numSubjects; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Total: " << calculateTotal() << endl;
        cout << "Average: " << calculateAverage() << endl;
    }

    void releaseMarks()
    {
        delete[] marks; // release the dynamically allocated marks
        marks = nullptr;
    }
};

int main()
{
    Student s;

    s.acceptDetails();
    s.acceptMarks();
    s.displayResult();
    // marks array is also safely released by the destructor when s goes out of scope,
    // but we can release explicitly too if needed:
    s.releaseMarks();

    return 0;
}