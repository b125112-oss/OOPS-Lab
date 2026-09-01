
#include <iostream>
using namespace std;

class RManager
{
private:
    int *tables;
    int n;

public:
    RManager(int numTables)
    {
        n = numTables;
        tables = new int[n];
    }

    ~RManager()
    {
        delete[] tables;
    }

    void inputTables()
    {
        cout << "Enter " << n << " table numbers:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> *(tables + i);
        }
    }

    int findSmallest() const
    {
        int smallest = *tables;
        for (int *p = tables; p < tables + n; p++)
        {
            if (*p < smallest)
            {
                smallest = *p;
            }
        }
        return smallest;
    }
};

int main()
{
    int n;
    cout << "Enter number of tables: ";
    cin >> n;

    RManager restaurant(n);

    restaurant.inputTables();

    cout << "\nSmallest table number: " << restaurant.findSmallest() << endl;

    return 0;
}