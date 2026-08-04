#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accNo;
    string holderName;
    float balance;

public:
    void enterDetails()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, holderName);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance += amount;
        cout << "Amount Deposited Successfully!" << endl;
    }

    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void display()
    {
        cout << "\nUpdated Account Details" << endl;
        cout << "Account Number : " << accNo << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Balance        : " << balance << endl;
    }
};

int main()
{
    BankAccount b;

    b.enterDetails();
    b.deposit();
    b.withdraw();
    b.display();

    return 0;
}