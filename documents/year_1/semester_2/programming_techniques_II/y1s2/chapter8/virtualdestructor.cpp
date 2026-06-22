#include<iostream>
using namespace std;

class Parent{
    protected:
    string name;
    public:
    Parent(string n=""){
        name=n;
    }
     ~Parent(){//difference between static binding and dynamic binding,virtual
        cout<<"Destroy parent object "<<endl;
    }
};
class Child:public Parent{
    private:
    int age;
    public:
    Child(int a=0,string n=""):Parent(n){
        age=a;
    }
    ~Child(){
        cout<<"destroy child object"<<endl;
    }
};

int main(){
    Parent*ptr;
    ptr=new Child(18,"jingyi");
    delete ptr;

    return 0;
}