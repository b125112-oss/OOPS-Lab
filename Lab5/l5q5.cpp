// Lab 5 - Problem 5: Modify a Value
// Demonstrates function overloading to add a value to an integer,
// add a value to a float, and modify an integer through its pointer.
// Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: add a value to an integer (by reference)
void modify(int &num, int value) {
    cout << "Before modification: " << num << endl;
    num += value;
    cout << "After modification:  " << num << endl;
}

// Overload 2: add a value to a floating-point number (by reference)
void modify(float &num, float value) {
    cout << "Before modification: " << num << endl;
    num += value;
    cout << "After modification:  " << num << endl;
}

// Overload 3: modify an integer using its pointer
void modify(int *num, int value) {
    cout << "Before modification: " << *num << endl;
    *num += value;
    cout << "After modification:  " << *num << endl;
}

int main() {
    int i, addI;
    float f, addF;
    int j, addJ;

    cout << "--- Modify a Value ---" << endl;

    cout << "Enter an integer and a value to add to it: ";
    cin >> i >> addI;
    modify(i, addI);

    cout << "\nEnter a floating-point number and a value to add to it: ";
    cin >> f >> addF;
    modify(f, addF);

    cout << "\nEnter an integer and a value to add via pointer: ";
    cin >> j >> addJ;
    modify(&j, addJ);

    return 0;
}