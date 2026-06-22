#include<iostream>
using namespace std;
class Course{
    private:
    string code;
    string name;
    public:
    Course(string c,string n):code(c),name(n){};
    string getCode(){
        return code;
    }
    string getName(){
        return code;
    }
};
class Student{
    private:
    string name;
    string matrix;
    Course*course;
    public:
    Student(string n,string m):name(n),matrix(m){};
    void regCourse(Course*c){
        course=c;
    }
    void display(){
        cout<<"Student name: "<<name<<endl;
        cout<<"Matrix: "<<matrix<<endl;
        cout<<"Course "<<course->getName()<<": "<<course->getCode()<<endl;
        
    }

};
int main(){
    Course *course=new Course("SECJ","PT2");
    Student student("jingyi","A23Cs");
    student.regCourse(course);
    student.display();

}