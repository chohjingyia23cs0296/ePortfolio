#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define an empty string object
    string name;

    // Define a string and initialize it with a literal
    string myName("Abu Bakar");

    // Define a string and initialize it with values from another string
    string yourName(myName);

    // Define a string and initialize it with a substring starting from position 5 of myName
    string aName(myName, 5);

    // Define a string and initialize it with a substring of length 3 from position 0 of myName
    string newName(myName, 0, 3);

    // Define a string with 5 characters, all 'A'
    string noName(5, 'A');

    // Output the results
    cout << "name: " << name << endl;
    cout << "myName: " << myName << endl;
    cout << "yourName: " << yourName << endl;
    cout << "aName: " << aName << endl;
    cout << "newName: " << newName << endl;
    cout << "noName: " << noName << endl;

    return 0;
}
