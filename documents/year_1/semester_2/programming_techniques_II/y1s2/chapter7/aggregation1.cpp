#include<iostream>
using namespace std;

class Address{
    private:
    string street;
    string town;
    string zip;
    public:
    Address(string s,string t,string z):street(s),town(t),zip(z){};
    string getFullAdress(){
        return street+" "+town+" "+zip+"\n";
    }
};
class Student{
    private:
    string firstname;
    string lastname;
    Address *home;
    public:
    Student(string fn,string ln,Address *homeaddress):firstname(fn),lastname(ln),home(homeaddress){};
    void print(){
        cout<<firstname<<"\t"<<lastname<<endl;
        cout<<home->getFullAdress()<<endl;
    }
};
int main(){
    Address *addr=new Address("T-2 taman ri triang","triang","28300");
    Student stu1("choh","jingyi",addr);
    stu1.print();
}