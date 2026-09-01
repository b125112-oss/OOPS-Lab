

#include <iostream>
using namespace std;

class ContactManager {
private:
    long *contacts;
    int n;

public:
    ContactManager(int numContacts) {
        n = numContacts;
        contacts = new long[n];
    }

    ~ContactManager() {
        delete[] contacts;
    }

    void accept() {
        cout << "Enter " << n << " contact numbers:\n";
        for (int i = 0; i < n; i++) {
            cin >> *(contacts + i);
        }
    }

    int search(long number) const {
        int index = 0;
        for (long *p = contacts; p < contacts + n; p++, index++) { 
            if (*p == number) {
                return index;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter number of contacts: ";
    cin >> n;

    ContactManager company(n);

    company.accept();

    long searchNumber;
    cout << "Enter contact number to search: ";
    cin >> searchNumber;

    int position = company.search(searchNumber);

    if (position != -1) {
        cout << "\nContact number found at position: " << position << endl;
    } else {
        cout << "\nContact number not found." << endl;
    }

    return 0;
}