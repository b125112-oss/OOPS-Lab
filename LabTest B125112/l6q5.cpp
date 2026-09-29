#include <iostream>
#include <string>
using namespace std;
/*An online shopping system stores an order status code:
• 1 = Processing
• 2 = Shipped
• 3 = Delivered
Write a function:
void updateStatus(int *status);
The function should update:
• Processing → Shipped
• Shipped → Delivered
Display the status before and after calling the function.*/

class OnlineShop
{
private:
    int orderStatus;
    string stat;
public:
    OnlineShop(int status)
    {
        orderStatus = status;
    }

    void updateStatus(int *status)
    {
        switch (*status)
        {
        case 2:
            *status = 2;
            stat="Shipped";
            break;
        case 3:
            *status = 3;
            stat="Delivered";
            break;
        default:
            cout << "Invalid status code." << endl;
        }
    }

    void displayStatus()
    {
        cout << "Current order status: " << orderStatus << " (" << stat << ")" << endl;
    }
};