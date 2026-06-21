#include<iostream>
using namespace std;

int main(){
    const int NUM_ROWS = 5; // Number of rows
    const int NUM_COLS = 5; // Number of columns
    double total,average ; // Accumulator
    int numbers[NUM_ROWS][NUM_COLS] =
    {{88, 97, 79, 86, 94},
    {86, 91, 78, 79, 84},
    {82, 91, 78, 79, 89}};

// Sum the array elements.

for (int row = 0; row < NUM_ROWS; row++){
    int total;
    for (int col = 0; col < NUM_COLS; col++)
        total += numbers[row][col];
    average=total/NUM_ROWS;
}

    cout << "The average is " << average << endl;
    return 0;
}