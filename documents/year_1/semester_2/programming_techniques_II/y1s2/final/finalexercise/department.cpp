#include<iostream>
using namespace std;
class Name{
    private:
    string firstname;
    string lastname;
    public:
    Name(string fN,string lN){
        firstname=fN;
        lastname=lN;
    }
    string getFullName(){
        return firstname+" "+lastname;
    }
};
class Lecturer{
    private:
    Name name;
    string staffId;
    public:
    Lecturer(string id,string fN,string lN):staffId(id),name(fN,lN){};
    string getLecturer(){
        return name.getFullName()+"\nLecturer id: "+staffId;
    }
};
class Department{
    private:
    Lecturer*lecturerDepart;
    public:
    
    Department(Lecturer*lectDepart){
        lecturerDepart=lectDepart;
    }
    void printDepartment(){
        cout<<"Lecturer name: "<<lecturerDepart->getLecturer();
    }
};
int main(){
    Lecturer *lecturer=new Lecturer("124","Abdullah ","Hamid"); 
    Department department(lecturer);
}