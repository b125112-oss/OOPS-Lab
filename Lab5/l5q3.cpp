// Lab 5 - Problem 3: Array Total
// Demonstrates function overloading to total elements of an integer array,
// a floating-point array, and a portion of an integer array.
// Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: total of an integer array
int total(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Overload 2: total of a floating-point array
float total(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Overload 3: total of the first "count" elements of an integer array
int total(int arr[], int size, int count) {
    int sum = 0;
    for (int i = 0; i < count && i < size; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int isize;
    cout << "--- Array Total ---" << endl;

    cout << "Enter the size of the integer array: ";
    cin >> isize;
    int *iarr = new int[isize];
    cout << "Enter " << isize << " integers: ";
    for (int i = 0; i < isize; i++)
        cin >> iarr[i];
    cout << "Total of integer array = " << total(iarr, isize) << endl;

    int fsize;
    cout << "\nEnter the size of the float array: ";
    cin >> fsize;
    float *farr = new float[fsize];
    cout << "Enter " << fsize << " floating-point values: ";
    for (int i = 0; i < fsize; i++)
        cin >> farr[i];
    cout << "Total of float array = " << total(farr, fsize) << endl;

    int count;
    cout << "\nEnter number of elements to consider from the integer array "
         << "(1 to " << isize << "): ";
    cin >> count;
    cout << "Total of first " << count << " elements of integer array = "
         << total(iarr, isize, count) << endl;

    delete[] iarr;
    delete[] farr;
    return 0;
}