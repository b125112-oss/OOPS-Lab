#include <iostream>
using namespace std;
// A sports centre stores the identification numbers of 6 pieces of equipment in an array.
class SportsStore
{
private:
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *ptr = arr;

public:
    void displayE()
    {
        cout << "Elements of array are:" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << *(ptr + i) << endl;
        }
    }
    void displayA()
    {
        cout << "Address of Elements of array are:" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << (ptr + i) << endl;
        }
    }
};
int main()
{
    SportsStore a;
    a.displayE();
    a.displayA();
    return 0;
}