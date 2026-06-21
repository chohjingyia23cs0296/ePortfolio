// This program uses nested structures.
#include <iostream>
#include <string>
using namespace std;

// The Date structure holds data about a date.
struct Date
{
    int month;
    int day;
    int year;
};

// The Place structure holds a physical address.
struct Place
{
    string address;
    string city;
    string state;
    string zip;
};

// The EmployeeInfo structure holds an employee's data.
struct EmployeeInfo
{
    string name;
    int employeeNumber;
    Date birthDate; // Nested structure
    Place residence; // Nested structure
};

int main()
{
    // Define a structure variable to hold info about the manager.
    const int SIZE=3;
    EmployeeInfo manager[SIZE];

     // Get the manager's name and employee number
     cout << "Enter the first manager's name: ";
     getline(cin, manager[0].name);
     cout << "Enter the first manager's employee number: ";
     cin >> manager[0].employeeNumber;

     // Get the manager's birth date
     cout << "Now enter the first manager's date of birth.\n";
     cout << "Month (up to 2 digits): ";
     cin >> manager[0].birthDate.month;
     cout << "Day (up to 2 digits): ";
     cin >> manager[0].birthDate.day;
     cout << "Year: ";
     cin >> manager[0].birthDate.year;
     cin.ignore(); // Skip the remaining newline character
     
     // Get the manager's residence information
     cout << "Enter the first manager's street address: ";
     getline(cin, manager[0].residence.address);
     cout << "City: ";
     getline(cin, manager[0].residence.city);
     cout << "State: ";
     getline(cin, manager[0].residence.state);
     cout << "ZIP Code: ";
     getline(cin, manager[0].residence.zip);
     
     manager[1].name="Zakwan";
     manager[1].employeeNumber=1233;
     manager[1].birthDate={8,6,2004};
     manager[1].residence.address="Block 5, Faculty of Computing, UTM";
     manager[1].residence.city="Pagoh";
     manager[1].residence.state="Johor";
     manager[1].residence.zip="83000";
     
     // Get the manager's name and employee number
     cout << "Enter the third manager's name: ";
     getline(cin, manager[2].name);
     cout << "Enter the third manager's employee number: ";
     cin >> manager[2].employeeNumber;

     // Get the manager's birth date
     cout << "Now enter the third manager's date of birth.\n";
     cout << "Month (up to 2 digits): ";
     cin >> manager[2].birthDate.month;
     cout << "Day (up to 2 digits): ";
     cin >> manager[2].birthDate.day;
     cout << "Year: ";
     cin >> manager[2].birthDate.year;
     cin.ignore(); // Skip the remaining newline character
     
     // Get the manager's residence information
     cout << "Enter the third manager's street address: ";
     getline(cin, manager[2].residence.address);
     cout << "City: ";
     getline(cin, manager[2].residence.city);
     cout << "State: ";
     getline(cin, manager[2].residence.state);
     cout << "ZIP Code: ";
     getline(cin, manager[2].residence.zip);

    for (int i=0;i<SIZE;i++){
     // Display the information just entered
     cout << "\nHere is the manager's information:\n";
     cout << manager[i].name << endl;
     cout << "Employee number " << manager[i].employeeNumber << endl;
     cout << "Date of birth: ";
     cout << manager[i].birthDate.month << "-";
     cout << manager[i].birthDate.day << "-";
     cout << manager[i].birthDate.year << endl;
     cout << "Place of residence:\n";
     cout << manager[i].residence.address << endl;
     cout << manager[i].residence.city << ", ";
     cout << manager[i].residence.state << " ";
     cout << manager[i].residence.zip << endl;
    }
    return 0;
}