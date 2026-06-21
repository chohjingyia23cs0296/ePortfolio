#include <iostream>
using namespace std;

void insertSort(int data[], int n) {
    int item;
    int pass, insertIndex;

    for (pass = 1; pass < n; pass++) {
        item = data[pass];
        insertIndex = pass;

        while (insertIndex > 0 && data[insertIndex - 1] > item) {
            data[insertIndex] = data[insertIndex - 1];
            insertIndex--;
        }

        data[insertIndex] = item;
    }
}

int main() {
    int data[] = {75,95,60,88,70};
    int n = sizeof(data) / sizeof(data[0]);

    insertSort(data, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
