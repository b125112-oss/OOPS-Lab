#include <iostream>
using namespace std;

class MatchFormat {
public:
    virtual ~MatchFormat() {}
    virtual int calculateTarget(int firstInningsScore) const { return firstInningsScore; }
};

class T20Match : public MatchFormat {
public:
    int calculateTarget(int firstInningsScore) const override {
        int margin = (firstInningsScore * 1 + 99) / 100;   // ceil(1% of score), integer-safe
        return firstInningsScore + margin;
    }
};

class ODIMatch : public MatchFormat {
public:
    int calculateTarget(int firstInningsScore) const override {
        int margin = (firstInningsScore * 2 + 99) / 100;   // ceil(2% of score), integer-safe
        return firstInningsScore + margin;
    }
};

int main() {
    int score;
    cout << "Enter first innings score: ";
    cin >> score;
    if (!cin || score < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    T20Match t20;
    ODIMatch odi;
    MatchFormat* m1 = &t20;
    MatchFormat* m2 = &odi;

    cout << "\nT20 target : " << m1->calculateTarget(score) << " runs\n";
    cout << "ODI target : " << m2->calculateTarget(score) << " runs\n";
    return 0;
}
