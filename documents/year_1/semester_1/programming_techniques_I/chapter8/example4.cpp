#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure declaration
struct Student
{
    string name;         // Student's name
    int idNum;           // Student ID number
    int creditHours;     // Credit hours enrolled
    double gpa;          // Current GPA
};

// Function prototype
void getData(Student *); // Function to get student data

int main()
{
    Student freshman;

    // Get the student data.
    cout << "Enter the following student data:\n";
    getData(&freshman); // Pass the address of freshman.
    cout << "\nHere is the student data you entered:\n";

    // Display the data stored in freshman
    cout << setprecision(3);
    cout << "Name: " << freshman.name << endl;
    cout << "ID Number: " << freshman.idNum << endl;
    cout << "Credit Hours: " << freshman.creditHours << endl;
    cout << "GPA: " << freshman.gpa << endl;

    return 0;
}

// Definition of function getData. Uses a pointer to a Student structure variable.
void getData(Student *s)
{
    // Get the student name.
    cout << "Student name: ";
    getline(cin, s->name);

    // Get the student ID number.
    cout << "Student ID Number: ";
    cin >> s->idNum;

    // Get the credit hours enrolled.
    cout << "Credit Hours Enrolled: ";
    cin >> s->creditHours;

    // Get the GPA.
    cout << "Current GPA: ";
    cin >> s->gpa;

}
