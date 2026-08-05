#include <iostream>
#include <string>
using namespace std;

class ElectricityBill
{
    int consumerNo, units;
    string consumerName;
    float bill;

public:
    void input()
    {
        cout << "Enter Consumer Number: ";
        cin >> consumerNo;
        cin.ignore();

        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);

        cout << "Enter Units Consumed: ";
        cin >> units;
    }

    void calculateBill()
    {
        if (units <= 100)
        {
            bill = units * 5;
        }
        else if (units <= 200)
        {
            bill = (100 * 5) + ((units - 100) * 7);
        }
        else
        {
            bill = (100 * 5) + (100 * 7) + ((units - 200) * 10);
        }
    }

    void display()
    {
        cout << "\n--- Electricity Bill ---\n";
        cout << "Consumer Number: " << consumerNo << endl;
        cout << "Consumer Name: " << consumerName << endl;
        cout << "Units Consumed: " << units << endl;
        cout << "Total Bill: Rs. " << bill << endl;
    }
};

int main()
{
    ElectricityBill e;

    e.input();
    e.calculateBill();
    e.display();

    return 0;
}