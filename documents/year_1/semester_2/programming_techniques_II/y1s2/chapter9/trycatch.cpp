#include<iostream>
using namespace std;
double divide(int numerator,int denomerator){
    if(denomerator==0)
    throw "ERROR.Cannot divide zero\n";
    else
    return static_cast<double>(numerator)/denomerator;
}
int main(){
    int num1,num2;
    double quotient;
    cout<<"Enter two number: ";
    cin>>num1>>num2;
    try{
        quotient=divide(num1,num2);
        cout<<"The quotient is "<<quotient<<endl;
        
    }
    catch(const char*exceptionString){//need const
        cout<<exceptionString;        
    }
    cout<<"End the program\n";
    return 0;
}
