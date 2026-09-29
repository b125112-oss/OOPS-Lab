
#include <iostream>
using namespace std;

class TextAnalyzer
{
private:
    char sentence[200];
    int digits;
    int alphabets;
    int spaces;

public:
    TextAnalyzer()
    {
        digits = 0;
        spaces = 0;
        alphabets = 0;
    }

    void accept()
    {
        cout << "Enter a sentence: ";
        cin.getline(sentence, 200);
    }

    void count()
    {
        char *ptr = sentence;
        while (*ptr != '\0')
        {
            if (*ptr >= '0' && *ptr <= '9')
            {
                digits++;
            }
            else if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
            {
                alphabets++;
            }
            else if (*ptr == ' ')
            {
                spaces++;
            }
            ptr++;
        }
    }

    void display() const
    {
        cout << "\nNumber of digits: " << digits << endl;
        cout << "Number of alphabetic characters: " << alphabets << endl;
        cout << "Number of spaces: " << spaces << endl;
    }
};

int main()
{
    TextAnalyzer analyzer;

    analyzer.accept();
    analyzer.count();
    analyzer.display();

    return 0;
}