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
    string name;
    Address address;
    public:
    Person(string n,string c):address(c),name(n){};
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
    Advisor(string n,string c,string f=""):faculty(f),Person(n,c){};
    string getFaculty(){
        return faculty;
    }
};
class Student:public Person{
    private:
    string program;
    Advisor *advisor;
    public:
    Student(string p,Advisor *a,string n,string c):program(p),advisor(a),Person(n,c){};
    void setAdvisor(Advisor*a){
        advisor=a;
    }
    Advisor* getAdvisor(){
        return advisor;
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
    Address studentaddress("Skudai");
    Address advisoraddress("Johor Bahru");
     Advisor advisor("Dr.Abu",advisoraddress.getCity(),"FC");
    Student student("Computer Science",&advisor,"Ali",studentaddress.getCity());
   
    cout<<"Student's name: "<<student.getName()<<endl;
    cout<<"Student's city: "<<student.getCity()<<endl;
    cout<<"Advisor's name: "<<student.getAdvisorName()<<endl;
    cout<<"Advisor's city: "<<student.getAdvisorCity()<<endl;
    cout<<"Advisor's faculty: "<<student.getAdvisor()->getFaculty()<<endl;
    return 0;
}