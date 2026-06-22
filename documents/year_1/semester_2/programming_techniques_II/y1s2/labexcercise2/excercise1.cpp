#include<iostream>
using namespace std;
class A{
    public:
    virtual void myFunA()=0;
    void greeting(){cout<<"Salam";}
};
//b
class Base1{
    public:
    int a;
    Base1(int b){
        a=b;
    }
};
class Base2{
    public:
    int c;
    Base2(int b){
         c=b;
    }
};
class Derived1:public Base1,public Base2{
    public:
    int x;
    Derived1(int b1, int b2, int _x) : Base1(b1), Base2(b2) {
        x = _x;
    }
};
//c
class BaseA{
    public:
    int a;
    BaseA(int b){
        a=b;
    }
};
class BaseB:virtual public BaseA{
    public:
    int c;
    BaseB(int d):BaseA(d*d){
        c=d;
    }
};
class BaseC:public BaseB{
    public:
    int e;
    BaseC(int f):BaseA(f*f*f), BaseB(f){
        e=f;
    }
};