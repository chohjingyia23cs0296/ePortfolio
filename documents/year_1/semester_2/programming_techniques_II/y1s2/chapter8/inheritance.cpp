#include<iostream>
using namespace std;

class BaseClass{
    public:
    BaseClass(){
        cout<<"This is base class constructor\n";//1
    }
    ~BaseClass(){
        cout<<"This is base class destructor\n";//3
    }
};
class DerivedClass:public BaseClass{
    public:
    DerivedClass(){
        cout<<"This is DerivedClass constructor.\n";//2
    }
    ~DerivedClass(){
        cout<<"this is derivedclasss destructor.\n";//4
    }
};
int main(){
    cout<<"We will define derived class object\n";
    DerivedClass object;
    cout<<"The program is now going end\n";
    return 0;
}