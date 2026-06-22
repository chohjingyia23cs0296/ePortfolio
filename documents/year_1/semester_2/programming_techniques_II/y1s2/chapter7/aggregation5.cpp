#include<iostream>
using namespace std;

class Course{
    private:
    string courseName;
    public:
    Course(string cN):courseName(cN){};
    string getCoursename(){
        return courseName;
    }

};
class Student{
    private:
    Course*course;
    public:
    Student():course(nullptr){};
    void enrollCourse(Course*c){
        course=c;
    }
    void withdrawCourse(){
        course=nullptr;
    }
    void showCourse(){
        if(course!=nullptr)
        cout<<"Course: "<<course->getCoursename();
        else
        cout<<"no course";
    }
};
int main(){
    Course course("PT2");
    Student s1;
    s1.enrollCourse(&course);
    s1.withdrawCourse();
    s1.showCourse();
}