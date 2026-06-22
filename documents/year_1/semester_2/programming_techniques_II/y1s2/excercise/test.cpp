#include <iostream>
using namespace std;

int main() {
    int n = 20; // Adjust size for a larger heart

    // Upper part of the heart
    for (int i = n / 2; i <= n; i += 2) {
        // Printing spaces before the first half
        for (int j = 1; j < n - i; j += 2) {
            cout << " ";
        }

        // Printing the first half of the heart
        for (int j = 1; j <= i * 2; j++) { // Widen the first half
            cout << "*";
        }

        // Printing spaces between the two halves
        for (int j = 1; j <= (n - i) * 2; j++) { // Widen the space between halves
            cout << " ";
        }

        // Printing the second half of the heart
        for (int j = 1; j <= i * 2; j++) { // Widen the second half
            cout << "*";
        }

        cout << endl;
    }

    // Lower part of the heart
    for (int i = n; i >= 1; i--) {
        // Printing spaces before the lower part
        for (int j = i; j < n; j++) {
            cout << " ";
        }

        // Printing the lower part of the heart
        for (int j = 1; j <= i * 4 - 1; j++) { // Widen the lower part
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
