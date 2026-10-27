#include <iostream>
using namespace std;

class SecurityScanner {
public:
    virtual ~SecurityScanner() {}
    virtual void scan(int threats) const { cout << "Generic scan. Threats: " << threats << endl; }
};

class BasicScanner : public SecurityScanner {
public:
    void scan(int threats) const override {
        cout << "Basic Scanner    -> Threats detected: " << threats << endl;
    }
};

class AdvancedScanner : public SecurityScanner {
public:
    void scan(int threats) const override {
        int removed = (threats * 90) / 100;     // 90% of detected threats removed (whole threats)
        int remaining = threats - removed;      // threats left after removal
        cout << "Advanced Scanner -> Threats detected: " << threats
             << ", Removed: " << removed
             << ", Remaining: " << remaining << endl;
    }
};

int main() {
    int threats;
    cout << "Enter number of threats: ";
    cin >> threats;
    if (!cin || threats < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    BasicScanner basic;
    AdvancedScanner advanced;
    SecurityScanner* s1 = &basic;
    SecurityScanner* s2 = &advanced;

    cout << endl;
    s1->scan(threats);
    s2->scan(threats);
    return 0;
}
