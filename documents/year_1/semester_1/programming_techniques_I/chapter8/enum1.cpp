#include <iostream>
#include <iomanip>
using namespace std;
struct Water{
    int FREEZING=32;
    int BOILING=212;
};
int main()
{
    // Enumerated constants for water temperatures
    Water water;

    // Variable to hold the water temperature entered by the user
    int waterTemp;

    // Prompt the user to enter the current water temperature
    cout << "Enter the current water temperature: ";
    cin >> waterTemp;

    // Check the temperature and print a corresponding message
    if (waterTemp <= water.FREEZING)
        cout << "The water is frozen.\n";
    else if (waterTemp >= water.BOILING)
        cout << "The water is boiling.\n";
    else
        cout << "The water is not frozen or boiling.\n";

    return 0;
}
