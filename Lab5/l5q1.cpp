// Lab 5 - Problem 1: Number Calculator
// Demonstrates function overloading with two integers, three integers,
// and two floating-point values. Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: sum of two integers
int calculate(int a, int b) {
    return a + b;
}

// Overload 2: sum of three integers
int calculate(int a, int b, int c) {
    return a + b + c;
}

// Overload 3: sum of two floating-point values
float calculate(float a, float b) {
    return a + b;
}

int main() {
    int i1, i2, i3;
    float f1, f2;

    cout << "--- Number Calculator ---" << endl;

    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    cout << "Sum = " << calculate(i1, i2) << endl;

    cout << "\nEnter three integers: ";
    cin >> i1 >> i2 >> i3;
    cout << "Sum = " << calculate(i1, i2, i3) << endl;

    cout << "\nEnter two floating-point values: ";
    cin >> f1 >> f2;
    cout << "Sum = " << calculate(f1, f2) << endl;

    return 0;
}