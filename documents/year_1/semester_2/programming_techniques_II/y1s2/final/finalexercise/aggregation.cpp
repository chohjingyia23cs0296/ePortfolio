#include<iostream>
using namespace std;

class Address{
    private:
    string street;
    string town;
    string zip;
    public:
    Address(string s,string t,string z):street(s),town(t),zip(z){};
    string getFullAddress(){
        return street+", "+town+", "+zip;
    }
};
class Student{
    private:
    string firstname;
    string lastname;
    Address*address;
    public:
    Student(string fN,string lN,Address*a):firstname(fN),lastname(lN),address(a){};
    void print(){
        cout<<"name: "<<firstname<<" "<<lastname<<endl;
        cout<<"Address: "<<address->getFullAddress();
    }

};
int main(){
    Address address("T-2","Tamsn","28300");
    Student *student=new Student("jing","yi",&address);
    Address *aa=new Address("T-2","Tamsn","28300");
    Student s1("jing","yi",aa);
    student->print();
    s1.print();
}