#include <iostream>
using namespace std;

int main() {
    int numofLine;
    cout << "Enter the number of lines: ";
    cin >> numofLine;

    for (int count = numofLine; count >= 1; count--) {
        for (int num = count; num >= 1; num--) {
            cout << num<<" "; 
        }
        cout << "\n";
    }

    return 0;
}
