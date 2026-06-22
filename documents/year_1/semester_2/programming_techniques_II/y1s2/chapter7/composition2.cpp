#include<iostream>
#include<string>
using namespace std;

class Name{
    private:
    string firstname;
    string lastname;
    public:
    Name(string first,string last){
        firstname=first;
        lastname=last;
    }
    string getFullName(){
        return firstname+" "+lastname;
    }
};
class Student{
    private:
    Name name;
    string address;
    public:
    Student(string first,string last,string address):name(first,last){
        this->address=address;
    }

    void print(){
        cout<<name.getFullName()<<"\n"<<address<<endl;
    }
};
int main(){
    string first,last;
    cout<<"First name; ";
    cin>>first;
    cout<<"Last name: ";
    cin>>last;
    Student stu1(first,last,"T-2");
    stu1.print();
}
