#include<iostream>
using namespace std;
class Worker{
    protected:
    string job;
    double salary;
    public:
    Worker(string _job="",double _salary=0.0){
        job=_job;
        salary=_salary;
    }
};
class Student{
    protected:
    string program;
    string faculty;
    public:
    Student(string _program="",string _faculty=""){
        program=_program;
        faculty=_faculty;
    }
};
class PartTimeStudent:public Student,public Worker{
    protected:
    int maxCreditAllowed;
    public:
    PartTimeStudent(int _maxCreditAllowed=0,string _program="",string _faculty="",string _job="",double _salary=0.0):
    Student(_program,_faculty),Worker(_job,_salary){
        maxCreditAllowed=_maxCreditAllowed;
        
    }
    void print()const{
        cout<<"Part Time Student Information\n\n";
        cout<<"Program: "<<program<<endl;
        cout<<"Faclty: "<<faculty<<endl;
        cout<<"Job: "<<job<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Max Credit Allowed: "<<maxCreditAllowed<<endl;
    }
};
int main(){
    PartTimeStudent pts(12, "Computer Science", "Engineering", "Library Assistant", 20000.0);
    pts.print();
}
