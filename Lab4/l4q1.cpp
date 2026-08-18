#include <iostream>
#include <string>
using namespace std;

class Diary {
private:
    string ownerName;
    int numEntries;
    string lastEntry;

public:
    Diary(string name, int entries, string last)
        : ownerName(name), numEntries(entries), lastEntry(last) {}

    friend void displayDiary(Diary d);
};

// Friend function accessing private members of Diary
void displayDiary(Diary d) {
    cout << "----- Diary Details -----" << endl;
    cout << "Owner Name    : " << d.ownerName << endl;
    cout << "No. of Entries: " << d.numEntries << endl;
    cout << "Last Entry    : " << d.lastEntry << endl;
}

int main() {
    string ownerName, lastEntry;
    int numEntries;

    cout << "Enter Owner Name: ";
    getline(cin, ownerName);

    cout << "Enter Number of Entries: ";
    cin >> numEntries;
    cin.ignore();

    cout << "Enter Last Entry: ";
    getline(cin, lastEntry);

    Diary d1(ownerName, numEntries, lastEntry);
    displayDiary(d1);
    return 0;
}
