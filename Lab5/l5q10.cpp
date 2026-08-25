// Lab 5 - Problem 10: Overloaded Data Processor
// Design: a "sum" processor that produces a meaningful result (the total)
// for every kind of input listed in the problem statement.
// Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: sum of two integers
int process(int a, int b) {
    return a + b;
}

// Overload 2: sum of an integer and a floating-point value
float process(int a, float b) {
    return a + b;
}

// Overload 3: sum of two floating-point values
float process(float a, float b) {
    return a + b;
}

// Overload 4: sum of an integer array using its size
int process(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Overload 5: sum of values accessed through two integer pointers
int process(int *a, int *b) {
    return *a + *b;
}

int main() {
    cout << "--- Overloaded Data Processor (Sum) ---" << endl;

    int i1, i2;
    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    cout << "Result = " << process(i1, i2) << endl;

    int ia;
    float fb;
    cout << "\nEnter an integer and a floating-point value: ";
    cin >> ia >> fb;
    cout << "Result = " << process(ia, fb) << endl;

    float f1, f2;
    cout << "\nEnter two floating-point values: ";
    cin >> f1 >> f2;
    cout << "Result = " << process(f1, f2) << endl;

    int size;
    cout << "\nEnter the size of an integer array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Result = " << process(arr, size) << endl;

    int p, q;
    cout << "\nEnter two more integers (to be processed via pointers): ";
    cin >> p >> q;
    cout << "Result = " << process(&p, &q) << endl;

    delete[] arr;
    return 0;
}