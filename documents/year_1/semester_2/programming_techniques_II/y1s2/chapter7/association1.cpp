#include<iostream>
using namespace std;
class Course{
    private:
    string name;
    string code;
    public:
    Course(string n,string c):name(n),code(c){};
    string getName(){
        return name;
    }
    string getCode(){
        return code;
    }
};
class Student{
    private:
    string name;
    string matrix;
    Course *subject;
    public:
    Student(string n,string m):name(n),matrix(m){};
    void regCourse(Course* s){
        subject=s;
    }
    void display(){
        cout<<"Name:"<<subject->getName()<<"\nMatrix: "<<subject->getCode()<<endl;
    }

};
int main(){
    Course *c=new Course("sadghj","asgd");
    Student s("Jingyi","528ge");
    s.regCourse(c);
    s.display();

}