#include<iostream>
using namespace std;

int main(){
    const int NUM_COINS=5;
double coins[NUM_COINS]={0.05,0.1,0.25,0.5,1.0};
double *doublePtr=coins;;
int count;

cout<<"Here are the values in the coins array:\n ";
for(count=0;count<NUM_COINS;count++){
    cout<<coins[count]<<" ";
}

cout<<"\nAnd here they are again:\n";
for(count=0;count<NUM_COINS;count++){
    cout<<*(coins+count)<<" ";
}cout<<endl;

cout<<"\nAnd here they are again:\n";
for (count=0;count<NUM_COINS;count++){
    cout<<*(doublePtr+count)<<" ";
}
cout<<"\nAnd here they are again:\n";
for (count = 0; count < NUM_COINS; count++) {
    cout << *doublePtr++ << " ";
     
}cout<<"\n";
for (count = 0; count < NUM_COINS; count++) {
    doublePtr = &coins[count];
      // Display the contents of the element.
      cout << *doublePtr << " ";
     
}cout<<"\n";


    return 0;
}