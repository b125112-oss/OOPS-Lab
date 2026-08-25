// Lab 5 - Problem 2: Value Comparison
// Demonstrates function overloading to find the larger value among
// two integers, two floats, and three integers. Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: larger of two integers
int larger(int a, int b) {
    return (a > b) ? a : b;
}

// Overload 2: larger of two floats
float larger(float a, float b) {
    return (a > b) ? a : b;
}

// Overload 3: largest of three integers
int larger(int a, int b, int c) {
    int maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

int main() {
    int i1, i2, i3;
    float f1, f2;

    cout << "--- Value Comparison ---" << endl;

    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    cout << "Larger value = " << larger(i1, i2) << endl;

    cout << "\nEnter two floating-point numbers: ";
    cin >> f1 >> f2;
    cout << "Larger value = " << larger(f1, f2) << endl;

    cout << "\nEnter three integers: ";
    cin >> i1 >> i2 >> i3;
    cout << "Largest value = " << larger(i1, i2, i3) << endl;

    return 0;
}