// Lab 5 - Problem 7: Compare Data Sets
// Demonstrates function overloading to compare two integers, two floats,
// and two integer arrays of equal size. Values are taken from the user.

#include <iostream>
using namespace std;

void compare(int a, int b) {
    if (a > b)
        cout << a << " is larger." << endl;
    else if (b > a)
        cout << b << " is larger." << endl;
    else
        cout << "Both values are equal." << endl;
}

void compare(float a, float b) {
    if (a > b)
        cout << a << " is larger." << endl;
    else if (b > a)
        cout << b << " is larger." << endl;
    else
        cout << "Both values are equal." << endl;
}

void compare(int arr1[], int arr2[], int size) {
    bool identical = true;
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            identical = false;
            break;
        }
    }
    if (identical)
        cout << "The arrays are identical." << endl;
    else
        cout << "The arrays are not identical." << endl;
}

int main() {
    cout << "--- Compare Data Sets ---" << endl;

    int i1, i2;
    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    compare(i1, i2);

    float f1, f2;
    cout << "\nEnter two floating-point numbers: ";
    cin >> f1 >> f2;
    compare(f1, f2);

    int size;
    cout << "\nEnter the common size of two integer arrays: ";
    cin >> size;
    int *arr1 = new int[size];
    int *arr2 = new int[size];

    cout << "Enter " << size << " integers for the first array: ";
    for (int i = 0; i < size; i++)
        cin >> arr1[i];

    cout << "Enter " << size << " integers for the second array: ";
    for (int i = 0; i < size; i++)
        cin >> arr2[i];

    compare(arr1, arr2, size);

    delete[] arr1;
    delete[] arr2;
    return 0;
}