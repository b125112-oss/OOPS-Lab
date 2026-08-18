#include <iostream>
#include <string>
using namespace std;

class GameManager; // forward declaration

class Player {
private:
    string playerName;
    int health;
    int score;
    int level;

public:
    Player(string name, int h, int s, int l)
        : playerName(name), health(h), score(s), level(l) {}

    // GameManager can access Player's private members
    friend class GameManager;
};

class GameManager {
public:
    void displayPlayerDetails(Player p) {
        cout << "Player Name: " << p.playerName << endl;
        cout << "Health     : " << p.health << endl;
        cout << "Score      : " << p.score << endl;
        cout << "Level      : " << p.level << endl;
    }

    void checkAlive(Player p) {
        cout << p.playerName << " is "
             << (p.health > 0 ? "Alive" : "Dead") << endl;
    }

    void displayLevelAndScore(Player p) {
        cout << "Level: " << p.level << ", Score: " << p.score << endl;
    }
};

int main() {
    string playerName;
    int health, score, level;

    cout << "Enter Player Name: ";
    getline(cin, playerName);
    cout << "Enter Health: ";
    cin >> health;
    cout << "Enter Score: ";
    cin >> score;
    cout << "Enter Level: ";
    cin >> level;

    Player p1(playerName, health, score, level);
    GameManager gm;

    gm.displayPlayerDetails(p1);
    gm.checkAlive(p1);
    gm.displayLevelAndScore(p1);
    return 0;
}