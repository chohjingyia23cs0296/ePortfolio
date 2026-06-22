#include<iostream>
using namespace std;

int main(){
    const int NUM_EMPLOYEES=6;
    int hours[NUM_EMPLOYEES];

    cout<<"Enter the hours worked by six employees. ";
    
    for(int count =0;count<NUM_EMPLOYEES;count++){
        cin>>hours[count];
    }
    cout<<"The hours you entered are: ";
    for(int i=0;i<NUM_EMPLOYEES;i++){
        cout<<" "<<hours[i];
    }

    return 0;
    

}
