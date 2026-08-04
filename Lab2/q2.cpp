#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length, width;

public:
    void read()
    {
        cout << "Enter length: ";
        cin >> length;

        cout << "Enter width: ";
        cin >> width;
    }

    float area()
    {
        return length * width;
    }

    float perimeter()
    {
        return 2 * (length + width);
    }

    void display()
    {
        cout << "\nRectangle Details" << endl;
        cout << "Length    : " << length << endl;
        cout << "Width     : " << width << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
    }
};

int main()
{
    Rectangle r;

    r.read();
    r.display();

    return 0;
}