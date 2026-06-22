
//lmbda function are function without names
#include<iostream>
using namespace std;

int main(){
    auto plus=[](auto a,auto b){
        return a+b;
    };
    cout<<"Integer plus: "<<plus(20,1)<<endl;
    cout<<"Number plus: "<<plus(2.5,1.3)<<endl;
    cout<<"String plus  :"<<plus(string("Hello "),string("World"))<<endl;
}