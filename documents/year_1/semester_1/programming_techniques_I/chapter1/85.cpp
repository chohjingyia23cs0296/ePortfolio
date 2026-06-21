#include <iostream>
using namespace std;

int main() {
    int numberOfYears, yearCounter = 1, M = 1;
    double totalRF = 0.0;
    int TM = 0;

    // Set the given values
    const int month = 12;
    const double initialTotalRF = 0.0;
    const int initialTM = 0;

    cout << "Enter the number of years: ";
    cin >> numberOfYears;

    if (numberOfYears < 1) {
        cout << "Invalid input. The number of years must be at least 1." << endl;
        return 1; // Exit with an error code
    }

    totalRF = initialTotalRF; // Set totalRF to the given initial value
    TM = initialTM;           // Set TM to the given initial value

    while (yearCounter <= numberOfYears) {
        while (M <= month) {
            double rainfall;
            cout << "Enter the inches of rainfall for year " << yearCounter << ", month " << M << ": ";
            cin >> rainfall;

            if (rainfall < 0) {
                cout << "Invalid input. Rainfall cannot be negative." << endl;
                return 1; // Exit with an error code
            }

            totalRF += rainfall;
            TM++;

            M++;
        }
        yearCounter++;
        M = 1;
    }

    double averageRainfall = totalRF / TM;

    cout << "Number of months: " << TM << endl;
    cout << "Total inches of rainfall: " << totalRF << " inches" << endl;
    cout << "Average rainfall per month: " << averageRainfall << " inches" << endl;

    return 0; // Exit normally
}
