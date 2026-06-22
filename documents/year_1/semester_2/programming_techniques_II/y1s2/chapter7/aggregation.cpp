#include <iostream>
#include <string>

using namespace std;
class Course{
    private:
    string code;
    string course;
    public:
    Course(string _code,string _course){
        code=_code;
        course=_course;
    }
};
class Student {
    private:
    Course *course;

    public:
    Student(){
        course=NULL;
    }
    void enrollCourse(Course *c){
        course=c;
    }
    void withdrawCourse(){
        course=NULL;
    }
};
int main(){
    Course c1("SECJ1013","Pt2");
    Student *s1=new Student;
    Student s2,s3;
    s1->enrollCourse(&c1);
    s2.enrollCourse(&c1);
    s3.enrollCourse(&c1);
    delete s1;

}