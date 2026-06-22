#include<iostream>
using namespace std;

class Name{
    private:
    string firstname;
    string lastname;
    public:
    Name(string first,string last):firstname(first),lastname(last){};
    string getFullName(){
        return firstname+" "+lastname;
    }
};
class Lecturer{
    private:
    Name name;
    string staffId;
    public:
    Lecturer(string first,string last,string id):staffId(id),name(first,last){};
    
    string getLecturer(){
        return name.getFullName()+"\nLecturer id: "+staffId;
    }
};
class Department{
    private:
    Lecturer* lecturerDepart;
    public:
    Department(Lecturer* lectDepart){
        lecturerDepart=lectDepart;
    }
    void pritDepartmet(){
        cout<<"Lecturer name: "<<lecturerDepart->getLecturer()<<endl;
    }
};
int main(){
    Lecturer *lect=new Lecturer("Abdullah","hamid","124");
    Department department(lect);
    department.pritDepartmet();

}