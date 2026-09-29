#include <iostream>
using namespace std;
class waterTank
{
private:
    int waterLevel;
    int *ptr = &waterLevel;

public:
    waterTank(int w)
    {
        waterLevel = w;
    }
    void display()
    {
        cout << "Current Water Level:" << *ptr << endl;
    }
    void refill()
    {
        int r;
        cout << "Enter amount to be refilled:" << endl;
        cin >> r;
        *ptr = *ptr + r;
    }
    void drain()
    {
        int d;
        cout << "Enter amount to be drained:" << endl;
        cin >> d;
        *ptr = *ptr - d;
    }
};
int main()
{
    waterTank w(50);
    w.display();
    w.refill();
    w.display();
    w.drain();
    w.display();
    return 0;
}