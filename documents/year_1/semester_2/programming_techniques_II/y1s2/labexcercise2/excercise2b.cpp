#include<iostream>
using namespace std;
class Class1{
    protected:
    int a;
    public:
    Class1(int x=1)
    {a=x;}
    void change()
    {a*=2;}
    int getVal()
    {change();
    return a;}
};

class Class2:public Class1{
    private:
    int b;
    public:
    Class2(int y=5)
    {b=y;}
    void change()
    {b*=10;}
};
int main (){
    Class1 object1;
    Class2 object2;
    cout<<object1.getVal()<<endl;
    /*This calls getVal() on object1, which in turn calls change(). 
    The change() method multiplies a by 2, so a becomes 2.*/
    cout<<object2.getVal()<<endl;
    /*The getVal() method calls change(). 
    However, Class2 does not override Class1's change() method that modifies a, 
    so the change() method of Class1 is called.
    */
    return 0;
}