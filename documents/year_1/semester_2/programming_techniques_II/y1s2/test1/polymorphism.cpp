//polymorphism is the ability of objects performing the same action differently
#include <iostream>
#include <string>

using namespace std;

// Base class BachelorProgram
class BachelorProgram {
public:
    string programName;

    // Constructor
    BachelorProgram(const string& name) {
        programName=name;
    };

    // Method to display program details
    void displayProgramDetails() const {
        cout << "Program Name: " << programName << endl;
    }
};

// Derived class DataEngineering
class DataEngineering : public BachelorProgram {
public:
    int dataCourses;

    // Constructor
    DataEngineering(const string& name, int courses) {
        BachelorProgram=name;
        courses=dataCourses;
    }
    // Method to display program details
    void displayProgramDetails() const {
        cout << "Data Engineering Program: " << programName << endl;
        cout << "Number of Data Courses: " << dataCourses << endl;
    }
};

// Derived class SoftwareEngineering
class SoftwareEngineering : public BachelorProgram {
public:
    int softwareCourses;

    // Constructor
    SoftwareEngineering(const string& name, int courses) : BachelorProgram(name), softwareCourses(courses) {}

    // Method to display program details
    void displayProgramDetails() const {
        cout << "Software Engineering Program: " << programName << endl;
        cout << "Number of Software Courses: " << softwareCourses << endl;
    }
};

int main() {
    // Create objects of DataEngineering and SoftwareEngineering
    DataEngineering dataEngineering("Data Science", 10);
    SoftwareEngineering softwareEngineering("Computer Science", 12);

    // Display program details
    cout << "Data Engineering Program:" << endl;
    dataEngineering.displayProgramDetails();
    cout << endl;

    cout << "Software Engineering Program:" << endl;
    softwareEngineering.displayProgramDetails();

    return 0;
}
