/*A teacher stores the marks of n students in an array.
Write a function that receives a pointer to the marks and the number of students. The
function should add 5 marks to every student.
Display the marks before and after modification.
Condition: Modify the original array using pointers.*/

#include <iostream>
using namespace std;
class stud
{
private:
    int arr[5];
    int *marks = arr;

public:
    void accept()
    {
        cout << "enter marks array:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> *(marks + i);
        }
    }
    void display(){
        cout<<"All Marks:"<<endl;
        cout<<"Marks are:"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout << *(marks + i) << endl;
        }
    }
};
int main()
{
    stud s;
    s.accept();
    s.display();
    return 0;
}