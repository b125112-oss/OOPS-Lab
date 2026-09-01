/*A podcast application stores the duration of 6 episodes.
Write a function that receives:
• A pointer to the first duration.
• The number of episodes.
Using pointer traversal, find and display the longest episode duration.
Condition: Do not use array indexing inside the function.*/
#include <iostream>
using namespace std;
class podcast
{
private:
    int duration[6];
    int *ptr = duration;
public:
    void accept()
    {
        cout << "Enter durations:" << endl;
        for (int i = 0; i < 6; i++)
        {
            cin >> *(ptr + i);
        }
    }
    void displayLongest()
    {
        int *maxPtr = ptr;
        for (int i = 1; i < 6; i++)
        {
            if (*(ptr + i) > *maxPtr)
            {
                maxPtr = ptr + i;
            }
        }
        cout << "Longest episode duration: " << *maxPtr << endl;
    }
};
int main()
{
    podcast p;
    p.accept();
    p.displayLongest();
    return 0;
}