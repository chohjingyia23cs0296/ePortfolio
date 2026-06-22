#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    public:
    Person(string n=""):name(n){};
    void set(string n){
        name=n;
    }
    void set(){
        cout<<"Enter the name";
        cin>>name;
    }
    void print()const{
        cout<<"Person's name: "<<name<<endl;
    }
    virtual void whoIam()const{
        cout<<"I am a person"<<endl;
    }
};
class Student:public Person{
    private:
    string matric;
    public:
    Student(string m="",string n=""):Person(n),matric(m){};
    void print()const{
        cout<<"Student name: "<<name<<endl;
        cout<<"Student matric: "<<matric<<endl;
    }
    void whoIam()const{
        cout<<"I am a Student"<<endl;
    }
};
int main() {
    Person person;
    Student student("123456", "Jane Doe");
    person.set("gdfhj");
    person.print();
    person.whoIam();

    student.set();
    student.print();
    student.whoIam();

    return 0;
}
