#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;  // Dynamically allocate memory for an integer

    cout << "Enter an integer: ";
    cin >> *ptr;  // Store the value in the allocated memory

    cout << "You entered: " << *ptr << endl;

    delete ptr;   // Release the allocated memory
    ptr = nullptr; // Good practice: avoid dangling pointer

    return 0;
}