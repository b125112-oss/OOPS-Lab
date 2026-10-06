#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string patientName;
    int patientID;
    int age;

public:
    Patient(string name, int id, int a) {
        patientName = name;
        patientID = id;
        age = a;
    }
};

class InPatient : public Patient {
private:
    double roomCharges;
    int numberOfDays;

public:
    InPatient(string name, int id, int a,
              double charges, int days)
        : Patient(name, id, a) {
        roomCharges = charges;
        numberOfDays = days;
    }

    void displayBill() {
        double totalBill = roomCharges * numberOfDays;

        cout << "\nHospital Bill";
        cout << "\nPatient Name : " << patientName;
        cout << "\nPatient ID   : " << patientID;
        cout << "\nAge          : " << age;
        cout << "\nRoom Charges : " << roomCharges << " per day";
        cout << "\nNumber Days  : " << numberOfDays;
        cout << "\nTotal Bill   : " << totalBill << endl;
    }
};

int main() {
    string name;
    int id, age, days;
    double roomCharges;

    cout << "Enter patient name: ";
    getline(cin, name);

    cout << "Enter patient ID: ";
    cin >> id;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter room charges per day: ";
    cin >> roomCharges;

    cout << "Enter number of days: ";
    cin >> days;

    InPatient patient(
        name, id, age,
        roomCharges, days
    );

    patient.displayBill();

    return 0;
}