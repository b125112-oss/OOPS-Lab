// Lab 5 - Problem 8: Counting Operation
// Demonstrates function overloading to count digits in an integer,
// count elements in an integer array, and count character occurrences.
// Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: count the number of digits in an integer
int count(int num) {
    if (num == 0) return 1;
    if (num < 0) num = -num;
    int digits = 0;
    while (num > 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

// Overload 2: count the number of elements in an integer array
int count(int arr[], int size) {
    (void)arr; // size already tells us the count; array kept for overload signature
    return size;
}

// Overload 3: count occurrences of a character in a character array
int count(char arr[], int size, char target) {
    int occurrences = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            occurrences++;
    return occurrences;
}

int main() {
    cout << "--- Counting Operation ---" << endl;

    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Number of digits = " << count(num) << endl;

    int isize;
    cout << "\nEnter the size of an integer array: ";
    cin >> isize;
    int *iarr = new int[isize];
    cout << "Enter " << isize << " integers: ";
    for (int i = 0; i < isize; i++)
        cin >> iarr[i];
    cout << "Number of elements in the array = " << count(iarr, isize) << endl;

    int csize;
    cout << "\nEnter the size of a character array: ";
    cin >> csize;
    char *carr = new char[csize];
    cout << "Enter " << csize << " characters (space separated): ";
    for (int i = 0; i < csize; i++)
        cin >> carr[i];

    char target;
    cout << "Enter the character to count occurrences of: ";
    cin >> target;
    cout << "Occurrences of '" << target << "' = " << count(carr, csize, target) << endl;

    delete[] iarr;
    delete[] carr;
    return 0;
}