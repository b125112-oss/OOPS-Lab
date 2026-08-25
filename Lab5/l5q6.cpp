// Lab 5 - Problem 6: Display Data
// Demonstrates function overloading to display an int, a float, a char,
// an integer array, and a character array using one common function name.
// Values are taken from the user.

#include <iostream>
using namespace std;

void display(int num) {
    cout << "Integer: " << num << endl;
}

void display(float num) {
    cout << "Float: " << num << endl;
}

void display(char ch) {
    cout << "Character: " << ch << endl;
}

void display(int arr[], int size) {
    cout << "Integer array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void display(char arr[], int size) {
    cout << "Character array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "--- Display Data ---" << endl;

    int i;
    cout << "Enter an integer: ";
    cin >> i;
    display(i);

    float f;
    cout << "Enter a floating-point number: ";
    cin >> f;
    display(f);

    char c;
    cout << "Enter a character: ";
    cin >> c;
    display(c);

    int isize;
    cout << "Enter the size of an integer array: ";
    cin >> isize;
    int *iarr = new int[isize];
    cout << "Enter " << isize << " integers: ";
    for (int k = 0; k < isize; k++)
        cin >> iarr[k];
    display(iarr, isize);

    int csize;
    cout << "Enter the size of a character array: ";
    cin >> csize;
    char *carr = new char[csize];
    cout << "Enter " << csize << " characters (space separated): ";
    for (int k = 0; k < csize; k++)
        cin >> carr[k];
    display(carr, csize);

    delete[] iarr;
    delete[] carr;
    return 0;
}