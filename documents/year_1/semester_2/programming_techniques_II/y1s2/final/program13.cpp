#include<iostream>
using namespace std;

class Address{
    private:
    string city;
    public:
    Address(string c):city(c){};
    void setCity(string c){
        city=c;
    }
    string getCity(){
        return city;
    }
};
class Person{
    protected:
    Address address;
    string name;
    public:
    Person(string n,string c):name(n),address(c){};
    string getName(){
        return name;
    }
    string getAddress(){
        return address.getCity();
    }
};
class Advisor:public Person{
    private:
    string faculty;
    public:
    Advisor(string f,string n,string c):Person(n,c){
        faculty=f;
    }
    string getFaculty(){
        return faculty;
    }
};
class Student:public Person{
    private:
    string program;
    Advisor*advisor;
    public:

    Student(string p,Advisor*a=NULL,string n,string c):advisor(a),Person(n,c){
        program=p;
    }
    void set(Advisor*a){
        advisor=a;
    }
    string getAdvisor(){
        return advisor->getFaculty();
    }
    string getCity(){
        return address.getCity();
    }
    string getAdvisorName(){
        return advisor->getName();
    }
    string getAdvisorCity(){
        return advisor->getAddress();
    }
};
int main(){
    Student student("",NULL,"Ali","Skudai");
    Advisor a("FC","Dr.Abu","Johor Bahru");

    cout<<"Student's name: "<<student.getName()<<endl;
    cout<<"Student's city: "<<student.getCity()<<endl;
    cout<<"Advisor name: "<<a.getName()<<endl;
    cout<<"Advisor city: "<<a.getAddress()<<endl;
    cout<<"Advisor faculty: "<<a.getFaculty()<<endl;
}
