#include <iostream>
using namespace std;
class battery
{
private:
    int bp;
    int *ptr = &bp;

public:
    battery(int b)
    {
        bp = b;
    }
    void display()
    {
        cout << "Current Battery:" << *ptr << endl;
    }
    void charge()
    {
        int c;
        cout << "Enter amount to be charged:" << endl;
        cin >> c;
        *ptr = *ptr + c;
    }
};

int main()
{
    battery b(80);
    b.display();
    b.charge();
    b.display();
    return 0;
}