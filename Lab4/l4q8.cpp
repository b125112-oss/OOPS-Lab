#include <iostream>
#include <string>
using namespace std;

class TicketChecker; // forward declaration

class TrainSeat {
private:
    int seatNumber;
    string passengerName;
    bool isBooked;

public:
    TrainSeat(int sn, string pn, bool booked)
        : seatNumber(sn), passengerName(pn), isBooked(booked) {}

    // TicketChecker can access TrainSeat's private members
    friend class TicketChecker;
};

class TicketChecker {
public:
    void displaySeatDetails(TrainSeat t) {
        cout << "Seat Number: " << t.seatNumber << endl;
    }

    void checkBookingStatus(TrainSeat t) {
        cout << "Status: " << (t.isBooked ? "Booked" : "Available") << endl;
        if (t.isBooked)
            cout << "Passenger Name: " << t.passengerName << endl;
    }
};

int main() {
    int seatNum1, seatNum2;
    string passengerName1, passengerName2;
    char bookedChoice1, bookedChoice2;
    bool booked1, booked2;

    cout << "--- Enter Seat 1 Details ---" << endl;
    cout << "Enter Seat Number: ";
    cin >> seatNum1;
    cout << "Is the seat booked? (y/n): ";
    cin >> bookedChoice1;
    booked1 = (bookedChoice1 == 'y' || bookedChoice1 == 'Y');
    cin.ignore();
    if (booked1) {
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName1);
    } else {
        passengerName1 = "";
    }

    cout << "\n--- Enter Seat 2 Details ---" << endl;
    cout << "Enter Seat Number: ";
    cin >> seatNum2;
    cout << "Is the seat booked? (y/n): ";
    cin >> bookedChoice2;
    booked2 = (bookedChoice2 == 'y' || bookedChoice2 == 'Y');
    cin.ignore();
    if (booked2) {
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName2);
    } else {
        passengerName2 = "";
    }

    TrainSeat seat1(seatNum1, passengerName1, booked1);
    TrainSeat seat2(seatNum2, passengerName2, booked2);
    TicketChecker checker;

    checker.displaySeatDetails(seat1);
    checker.checkBookingStatus(seat1);
    cout << endl;
    checker.displaySeatDetails(seat2);
    checker.checkBookingStatus(seat2);
    return 0;
}