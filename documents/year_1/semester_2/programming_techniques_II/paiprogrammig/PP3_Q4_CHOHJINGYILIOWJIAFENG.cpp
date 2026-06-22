#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName, title;
    int year;

    cout << "Enter author of the book -> ";
    cin >> firstName >> lastName;
    cin.ignore(); // Ignore newline character
    cout << "Enter year of published -> ";
    cin >> year;
    cin.ignore(); // Ignore newline character
    cout << "Enter a book title -> ";
    getline(cin, title);

    // Format the output
    cout << "\nThe Formatted Book Reference:" << endl;
    cout << lastName << ", " << firstName << " (" << year << ") " << title << endl;

    return 0;
}
