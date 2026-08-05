#include <iostream>
#include <string>
using namespace std;

class LibraryBook
{
    int bookID, days;
    string title, studentName;
    float fine;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Student Name: ";
        getline(cin, studentName);

        cout << "Enter Number of Days Issued: ";
        cin >> days;
    }

    void calculateFine()
    {
        if (days > 15)
            fine = (days - 15) * 2;
        else
            fine = 0;
    }

    void display()
    {
        cout << "\n--- Transaction Details ---\n";
        cout << "Book ID: " << bookID << endl;
        cout << "Book Title: " << title << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Days Issued: " << days << endl;
        cout << "Fine: Rs. " << fine << endl;
    }
};

int main()
{
    LibraryBook b;

    b.input();
    b.calculateFine();
    b.display();

    return 0;
}