#include <iostream>
using namespace std;

class InternalExam {
protected:
    int internalMarks;

public:
    InternalExam(int marks) {
        internalMarks = marks;
    }

    void display() {
        cout << "Internal Marks: " << internalMarks << endl;
    }
};

class ExternalExam {
protected:
    int externalMarks;

public:
    ExternalExam(int marks) {
        externalMarks = marks;
    }

    void display() {
        cout << "External Marks: " << externalMarks << endl;
    }
};

class FinalResult : public InternalExam, public ExternalExam {
public:
    FinalResult(int internal, int external)
        : InternalExam(internal), ExternalExam(external) {}

    void displayResult() {
        cout << "\nFinal Result\n";

        // Resolving ambiguity using scope resolution
        InternalExam::display();
        ExternalExam::display();

        cout << "Total Marks: "
             << internalMarks + externalMarks << endl;
    }
};

int main() {
    int internal, external;

    cout << "Enter internal marks: ";
    cin >> internal;

    cout << "Enter external marks: ";
    cin >> external;

    FinalResult obj(internal, external);

    obj.displayResult();

    return 0;
}