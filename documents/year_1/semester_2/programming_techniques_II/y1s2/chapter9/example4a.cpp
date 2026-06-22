#include<iostream>
using namespace std;

template<class T>
T times10(T num){
    return 10*num;
}
int main(){
    int ival=3;
    double dval=2.55;
    cout<<times10(ival);
    cout<<times10(dval);
}