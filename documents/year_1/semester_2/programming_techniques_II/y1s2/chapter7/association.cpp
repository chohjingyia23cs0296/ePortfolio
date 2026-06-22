#include<iostream>
#include<string>
using namespace std;

class Course{
    private:
    string name,code;
    public:Course(string n,string c);
    string getname(){
        return name;
    }
    string getCode(){
        return code;
    }
};
class Student{
    private:
    string name,matrix;
    Course*subject;
    public:
    Student(string n,string m);
    void regCourse(Course*subject);
    void display();
};
Student::Student(string n,string m){
    name=n;
    matrix=m;
}
void Student::regCourse(Course*c){
    subject=c;
}
void Student::display(){
    cout<<name<<"("<<matrix<<") register"<<subject->getname()<<"("<<subject->getCode()<<")"<<endl;
}
Course::Course(string n,string c){
    name=n;
    code=c;
}
int main(){
    Course*c=new Course("PT2","SCSJ1023");
    Student s("Ainul Hashim","A18CS0044");
    s.regCourse(c);
    s.display();
    return 0;
}