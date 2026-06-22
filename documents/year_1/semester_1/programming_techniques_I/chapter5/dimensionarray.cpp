#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLUMNS = 4;

void showArray(int array[][COLUMNS], int rows);

int main() {
    int table1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int table2[ROWS][COLUMNS] = {
    
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };

    cout << "The contents of table1 are:\n";
    showArray(table1, ROWS);

    cout << "The contents of table2 are:\n";
    showArray(table2, ROWS);

    return 0;
}

void showArray(int array[][COLUMNS], int rows) {
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            cout << setw(4) << array[x][y] << " ";
        }
        cout << endl;
    }
}
