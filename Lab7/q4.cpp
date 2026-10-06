#include <iostream>
using namespace std;

class BankAccount {
protected:
    long long accountNumber;
    double balance;

public:
    BankAccount(long long accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(long long accNo, double bal, double rate)
        : BankAccount(accNo, bal) {
        interestRate = rate;
    }

    void updateBalance() {
        double interest = balance * interestRate / 100.0;
        balance += interest;

        cout << "\nSavings Account";
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nInterest      : " << interest;
        cout << "\nUpdated Balance: " << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double minimumBalance;
    double maintenanceCharge;

public:
    CurrentAccount(long long accNo, double bal,
                   double minBal, double charge)
        : BankAccount(accNo, bal) {
        minimumBalance = minBal;
        maintenanceCharge = charge;
    }

    void updateBalance() {
        cout << "\nCurrent Account";
        cout << "\nAccount Number: " << accountNumber;

        if (balance < minimumBalance) {
            balance -= maintenanceCharge;
            cout << "\nMaintenance Charge Deducted: "
                 << maintenanceCharge;
        } else {
            cout << "\nNo Maintenance Charge";
        }

        cout << "\nUpdated Balance: " << balance << endl;
    }
};

int main() {
    long long accNo;
    double balance;
    double interestRate;
    double minimumBalance;
    double maintenanceCharge;

    cout << "Enter account number for Savings Account: ";
    cin >> accNo;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter interest rate (%): ";
    cin >> interestRate;

    SavingsAccount savings(
        accNo, balance, interestRate
    );

    cout << "\nEnter account number for Current Account: ";
    cin >> accNo;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter minimum balance: ";
    cin >> minimumBalance;

    cout << "Enter maintenance charge: ";
    cin >> maintenanceCharge;

    CurrentAccount current(
        accNo,
        balance,
        minimumBalance,
        maintenanceCharge
    );

    savings.updateBalance();
    current.updateBalance();

    return 0;
}