#include<iostream>
using namespace std;
int main(){
/*
const int SIZE = 25;
int *arrayptr;
arrayptr = new double[SIZE];
for(int i = 0; i < SIZE; i++)
*arrayptr[i] = i * i;
for(int i = 0; i < SIZE; i++)
cout <<*arrayptr + i<<endl;
*/

    const int SIZE = 25;
    double *arrayptr;
    arrayptr = new double[SIZE];

    for(int i = 0; i < SIZE; i++)
arrayptr[i] = i * i;

    for(int i = 0; i < SIZE; i++)
    cout <<*(arrayptr + i)<<endl;

    delete[] arrayptr;

return 0;
}