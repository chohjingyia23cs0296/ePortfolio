#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    const int SIZE=5;
    int hours[SIZE];
    double payRate[SIZE];
    cout<<"Enter the hours worked by 5 employees and their hourly pay rates."<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Hours worked by employee #"<<i+1<<":";
        cin>>hours[i];
        cout<<"Hours pay rate for employee #"<<i+1<<":";
        cin>>payRate[i];
    }
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Here is the gross pay for each employee: "<<endl;
    for(int i=0;i<SIZE;i++){
        double grossPay=hours[i]*payRate[i];
        cout<<"Employee #"<<i+1<<":"<<grossPay<<endl;
        
    }
 return 0; }