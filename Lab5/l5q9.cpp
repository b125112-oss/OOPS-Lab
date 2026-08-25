// Lab 5 - Problem 9: Maximum Value Finder
// Demonstrates function overloading to find the maximum between two
// integers, two integer pointers, and all elements of an integer array
// (accessed via pointer and size). Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: maximum of two integers
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Overload 2: maximum of two values accessed through integer pointers
int maximum(int *a, int *b) {
    return (*a > *b) ? *a : *b;
}

// Overload 3: maximum among all elements of an integer array (pointer + size)
int maximum(int *arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int main() {
    cout << "--- Maximum Value Finder ---" << endl;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Max of two integers = " << maximum(a, b) << endl;
    cout << "Max using pointers to the same values = " << maximum(&a, &b) << endl;

    int size;
    cout << "\nEnter the size of an integer array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Max in array = " << maximum(arr, size) << endl;

    delete[] arr;
    return 0;
}