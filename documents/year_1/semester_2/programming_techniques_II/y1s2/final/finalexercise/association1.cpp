#include<iostream>
using namespace std;

class Course{
    private:
    string code;
    public:
    Course(string c):code(c){};
    string getCode(){
        return code;
    }

};
class Lecturer{
    private:
    string name;
    Course*course;

    public:
    Lecturer(string n):name(n){};
    void teach(Course*c){
        course=c;
    }
    void display(){
        cout<<"Lecturer: "<<name<<endl;
        cout<<"Course: "<<course->getCode()<<endl;
    }
};
int main(){
    Lecturer lecturer("jingyi");
    Course *course=new Course("PT2");
    lecturer.teach(course);
    lecturer.display();
}