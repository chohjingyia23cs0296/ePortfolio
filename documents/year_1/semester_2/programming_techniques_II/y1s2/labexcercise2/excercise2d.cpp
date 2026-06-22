#include<iostream>
using namespace std;

class Base{
    protected:
    int baseVar;
    public:
    Base(int val=2)
    {baseVar=val;}
    int getVar(){
        return baseVar;
    }
};
class Derived:public Base{
    private:
    int derivedVar;
    public:
    Derived(int val=100)
    {derivedVar=val;}
    int getVar()
    {
        return derivedVar;
    }
};
int main(){
    Base *optr;
    Derived object;
    optr=&object;
    cout<<optr->getVar()<<endl;
    /*Base::getVar() is not virtual, method resolution is based on the static type of the pointer. 
    Hence, Base::getVar() is called, returning the value of baseVar (which is 2).*/
    return 0;
}




