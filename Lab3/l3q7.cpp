#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Step 1: Allocate memory for m row pointers
    int** matrix = new int*[m];

    // Step 2: Allocate memory for each row (n columns)
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    // Accept matrix elements
    cout << "Enter " << m * n << " elements:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "\nThe matrix is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate: free each row first, then the row-pointer array
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}