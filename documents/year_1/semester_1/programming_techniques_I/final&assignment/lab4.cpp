#include<iostream>
#include<iomanip>
using namespace std;
//CHOH JING YI A23CS0296 09.51 11/1/2024
int main() {
    int num_value;
    cout << "Enter the number of values: ";
    cin >> num_value;
     double *arr=new double;
     double total=0.0;

    cout << "Enter values in array: \n";
    for (int x = 0; x < num_value; x++) {
        cin >> arr[x];
        total += arr[x];  
    }
    double average = total / num_value;
    cout << fixed << setprecision(1);
    cout << "The average of the array numbers is " << average << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}


