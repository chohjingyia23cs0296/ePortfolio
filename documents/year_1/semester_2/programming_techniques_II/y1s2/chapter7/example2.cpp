#include<iostream>
#include<vector>
using namespace std;

class Course{
    private:
    string courseName;
    public:
    Course(string cN):courseName(cN){};
    string getCourseName(){
        return courseName;
    }
};
class Student{
    private:
    string name;
    Course*course;
    public:
    void enrollCourse(Course* c) {
        course = c;
    }
    void showCourse() {
        if (course != nullptr) {
            cout << name << " enrolled in " << course->getCourseName() << endl;
        } else {
            cout << name << " not enrolled in any course" << endl;
        }
    }
};
class Lecturer{
    string name;
    vector<Course*>course;
    public:
    Lecturer(string n):name(n){};
    void teachCourse(Course*c){
        course.push_back(c);
    }

    void showCourse(){
        cout<<"Lecturer name: ";
        for(Course*c:course){
            cout<<name<<"-"<<c->getCourseName()<<endl;
        }
    }
};
int main(){
    Course course1("PT2");
    Lecturer lecturer("jingiy");
   lecturer.teachCourse(&course1);
   lecturer.showCourse();
}