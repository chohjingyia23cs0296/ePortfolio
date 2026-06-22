#include<iostream>
using namespace std;

class Name{
    private:
    string firstName;
    string lastName;
    public:
    Name(string fN,string lN):firstName(fN),lastName(lN){};
    string getFullName(){
        return firstName+" "+lastName;
    }
};
class Student{
    private:
    Name name;
    string address;
    public:
    Student(string a,string fN,string lN):address(a),name(fN,lN){};
    void print(){
        cout<<"Student: "<<name.getFullName()<<endl;
        cout<<"Address: "<<address<<endl;
    }
};
int main(){
    string first,last;
    cin>>first;
    cin>>last;
    Student student("T-2 Taman ",first,last);
    student.print();
}