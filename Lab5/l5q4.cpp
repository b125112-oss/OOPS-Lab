// Lab 5 - Problem 4: Element Search
// Demonstrates function overloading to search for an integer in an int
// array, a character in a char array, and an integer within a range.
// Values are taken from the user.

#include <iostream>
using namespace std;

// Overload 1: search for an integer in an integer array
int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Overload 2: search for a character in a character array
int search(char arr[], int size, char key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Overload 3: search for an integer within a specified range [start, end]
int search(int arr[], int start, int end, int key) {
    for (int i = start; i <= end; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

void report(const string& label, int pos) {
    if (pos != -1)
        cout << label << " found at index " << pos << endl;
    else
        cout << label << " not found." << endl;
}

int main() {
    cout << "--- Element Search ---" << endl;

    int isize;
    cout << "Enter the size of the integer array: ";
    cin >> isize;
    int *iarr = new int[isize];
    cout << "Enter " << isize << " integers: ";
    for (int i = 0; i < isize; i++)
        cin >> iarr[i];

    int key;
    cout << "Enter an integer to search for: ";
    cin >> key;
    report("Integer " + to_string(key), search(iarr, isize, key));

    int csize;
    cout << "\nEnter the size of the character array: ";
    cin >> csize;
    char *carr = new char[csize];
    cout << "Enter " << csize << " characters (space separated): ";
    for (int i = 0; i < csize; i++)
        cin >> carr[i];

    char ckey;
    cout << "Enter a character to search for: ";
    cin >> ckey;
    report(string("Character '") + ckey + "'", search(carr, csize, ckey));

    int start, end, rkey;
    cout << "\nEnter a range [start end] within the integer array (0-indexed): ";
    cin >> start >> end;
    cout << "Enter an integer to search for within that range: ";
    cin >> rkey;
    report("Integer " + to_string(rkey) + " in the given range",
           search(iarr, start, end, rkey));

    delete[] iarr;
    delete[] carr;
    return 0;
}