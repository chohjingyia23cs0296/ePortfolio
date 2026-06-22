//Program 9.4
#include <iostream> 
using namespace std;

 
 class Class1{
    protected:
    int a;
    public: 
    Class1 (int x = 1)
    { a = x; } 
    int getVal () 
    { return a; }
    
    
 };
 class Class2 : public Class1 {
    private:
    int b; 
    public: Class2 (int y = 5) {
        b=y;
    } 
    int getVal () { 
        return b; 
    } 
};
int main (){
    Class1 object1;
    Class2 object2;
    cout<<object1.getVal()<<endl;//
    /*object1 is an instance of Class1. The constructor of Class1 initializes a to 1 by default.
    When getVal() is called on object1, it returns a, which is 1.
    object2.getVal() Output:
*/

    cout<<object2.getVal()<<endl;
    /*object2 is an instance of Class2. The constructor of Class2 initializes b to 5 by default.
    When getVal() is called on object2, it returns b, which is 5.*/
    return 0;
} 