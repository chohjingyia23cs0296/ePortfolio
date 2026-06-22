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
    Person(string n,string a):name(n),address(a){};
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
    Advisor(string f,string n,string a):Person(n,a){
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
    Student(string p,string n,string a,Advisor*ad):Person(n,a),advisor(ad){
        program=p;
    }

    void setAdvisor(Advisor*a){
        advisor=a;
    }
    Advisor* getAdvisor(){
        return advisor;
    }
    string getCity(){
         return address.getCity();
    }
    string getAdvisorname(){
        return advisor->getName();
    }
    string getAdvisorCity(){
        return advisor->getAddress();
    }

};
int main(){
    Address studentaddress("Skudai");
    Address advisoraddress("Johor Bahru");
    Advisor advisor("FC","Dr.Abu",advisoraddress.getCity());
    Student student("PT2","Ali",studentaddress.getCity(),&advisor);

    cout<<"Student's name: "<<student.getName()<<endl;
    cout<<"Student's city: "<<student.getCity()<<endl;
    cout<<"Advisor's name: "<<advisor.getName()<<endl;
    cout<<"Advisor's city: "<<advisor.getAddress()<<endl;
    cout<<"Advisor's faculty: "<<advisor.getFaculty()<<endl;

}