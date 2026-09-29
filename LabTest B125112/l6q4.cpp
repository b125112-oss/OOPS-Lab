#include <iostream>
using namespace std;
/*
A railway system stores 8 seat numbers in an array.
A seat number at a position entered by the user was recorded incorrectly.
Use pointer arithmetic to update that seat number.
Display the list before and after correction.
*/
class RailwaySystem
{
private:
    int SeatArr[8];
    int *ptr = SeatArr;

public:
    void accept()
    {
        cout << "Enter seats:" << endl;
        for (int i = 0; i < 8; i++)
        {
            cin >> *(ptr + i);
        }
    }
    void display()
    {
        cout << "Seat Numbers are:" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << *(ptr + i) << endl;
        }
    }
    void correct()
    {
        int pos, newSeat;
        cout<<"Enter position to correct:"<<endl;
        cin>> pos;
        if (pos < 0 || pos >= 8) {
            cout << "Invalid position. Please enter a position between 0 and 7." << endl;
            return;
        }
        cout<<"Enter new seat number:"<<endl;
        cin>> newSeat;
        *(ptr + pos) = newSeat;
    }
};
int main()
{
    RailwaySystem r;
    r.accept();
    r.display();
    r.correct();
    r.display();
    return 0;
}