#include <iostream>
using namespace std;

void BubbleSort(int data[], int listSize, int &comparisonCount, int &swapCount) {
    int pass, tempValue;
    bool sorted=false;
    for (pass = 1; pass < listSize; pass++) { 
        sorted=true;
        for (int x = 0; x < listSize - pass; x++) { 
            comparisonCount++;

            if (data[x] > data[x + 1]) { 
                swapCount++;
 
                tempValue = data[x];
                data[x] = data[x + 1];
                data[x + 1] = tempValue;
                sorted=false;
            }
        }
    }
} 

int main() {
    int myNum[5] = {75, 95, 60, 88, 70};
    
    int comparisonCount = 0; 
    int swapCount = 0;      

    BubbleSort(myNum, 5, comparisonCount, swapCount);

    cout << "Numbers after sorted in ascending order: ";
    for (int i = 0; i < 5; i++) {
        cout << myNum[i] << " ";
    }
    cout << endl;

    cout << "Total number of comparisons: " << comparisonCount << endl;
    cout << "Total number of swaps: " << swapCount << endl;

    system("pause");
    return 0;
}

