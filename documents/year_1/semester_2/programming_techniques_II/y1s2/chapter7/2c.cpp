#include<iostream>
using namespace std;
class Student{
    private:
    string studName;
    int studid;
};
class Professor{
    private:
    int numOfTecahing;
    string profname;
    public:
    Professor(string prof){
        profname=prof;
    }
    string display(){
        return "Professor name"+profname+"\n";
    }
    ~Professor(){

    }
    
};
class College{
    private:
    string name;
    Professor* prof;
    Student stud;
    public:
    College(string n,Professor*professor):name(n),prof(professor){};
    ~College();
};