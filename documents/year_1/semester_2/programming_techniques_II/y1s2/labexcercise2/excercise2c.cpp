#include<iostream>
using namespace std;

class Class1{
    protected:
    int a;
    public:
    Class1(int x=1)
    {a=x;}
    virtual void change()
    {a*=2;}
    int getVal()
    {change();return a;}
};

class Class2:public Class1{
    private:
    int b;
    public:
    Class2(int y=5)
    {b=y;}
    virtual void change()
    {b*=10;}
};
int main (){
    Class1 object1;
    Class2 object2;
    cout<<object1.getVal()<<endl;/*
    The getVal() method calls change(). Since object1 is of type Class1, 
    Class1's change() method is invoked, multiplying a by 2 (from 1 to 2).
    getVal() then returns the updated value of a, which is 2.
    */
    cout<<object2.getVal()<<endl;
    /*The getVal() method calls change(). 
    Since change() is a virtual function and object2 is of type Class2, Class2's overridden change() 
    method is invoked, multiplying b by 10 (from 5 to 50).
    However, getVal() returns a, not b. Since Class2's change() method does not modify a,
    the value of a remains unchanged at 1.*/
    return 0;
}