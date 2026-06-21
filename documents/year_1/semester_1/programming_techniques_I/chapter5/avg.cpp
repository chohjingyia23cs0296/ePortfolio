#include <iostream>
using namespace std;
double avgArray(int userNums[], int SIZE);
int main()
{
    const int SIZE = 10;
    int userNums[SIZE];
    cout << "Enter 10 numbers: ";
    for (int count = 0; count < SIZE; count++)
    {
        cout << "#" << (count + 1) << " ";
        cin >> userNums[count];
        }
        cout << "The average of those numbers is ";
        cout << avgArray(userNums,SIZE) << endl;
        return 0;
    }
double avgArray(int userNums[],int SIZE){
    int total=0;
    for(int i=1;i<SIZE;i++){
        total+=userNums[i];
    }
    return static_cast<double>(total)/SIZE;
 
}