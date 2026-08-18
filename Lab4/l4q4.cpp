#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string songName;
    string artistName;
    int duration; // duration in seconds

public:
    Song(string sn, string an, int d)
        : songName(sn), artistName(an), duration(d) {}

    friend void compareSongs(Song s1, Song s2);
};

// Friend function receiving both Song objects as arguments
void compareSongs(Song s1, Song s2) {
    cout << "Song 1: " << s1.songName << " by " << s1.artistName
         << " (" << s1.duration << "s)" << endl;
    cout << "Song 2: " << s2.songName << " by " << s2.artistName
         << " (" << s2.duration << "s)" << endl;

    if (s1.duration > s2.duration)
        cout << s1.songName << " is longer." << endl;
    else if (s2.duration > s1.duration)
        cout << s2.songName << " is longer." << endl;
    else
        cout << "Both songs have the same duration." << endl;
}

int main() {
    string songName1, artistName1, songName2, artistName2;
    int duration1, duration2;

    cout << "--- Enter Song 1 Details ---" << endl;
    cout << "Enter Song Name: ";
    getline(cin, songName1);
    cout << "Enter Artist Name: ";
    getline(cin, artistName1);
    cout << "Enter Duration (in seconds): ";
    cin >> duration1;
    cin.ignore();

    cout << "\n--- Enter Song 2 Details ---" << endl;
    cout << "Enter Song Name: ";
    getline(cin, songName2);
    cout << "Enter Artist Name: ";
    getline(cin, artistName2);
    cout << "Enter Duration (in seconds): ";
    cin >> duration2;
    cin.ignore();

    Song s1(songName1, artistName1, duration1);
    Song s2(songName2, artistName2, duration2);

    compareSongs(s1, s2);
    return 0;
}