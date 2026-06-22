#include<iostream>
using namespace std;
double add(double a,double b){
    return a+b;
    
}
double subtract(double a,double b){
    return a-b;
}
double multiply(double a,double b){
    return a*b;
    
}
double divide(double a,double b){
    return a/b;
    
}
typedef double(*binaryfunction)(double,double);

/*
binaryfunction getfunction(char op){
    switch(op){
       case '+':return add;
       case '-': return subtract;
       case '*':return multiply;
       case '/':return divide;
       default:return nullptr;
    }
}
auto x=getfunction('+');
   binaryfunction y=getfunction('-');
   cout<<x(2,3)<<endl;
   cout<<y(4,5);

*/

void doCalculation(double a,double b,binaryfunction x){
    double r=x(a,b);
    cout<<"Result: "<<r<<endl;
}
int main(){
   
   doCalculation(3,5,divide);
   doCalculation(4,6,[](double a,double b){return a*b;});
}
