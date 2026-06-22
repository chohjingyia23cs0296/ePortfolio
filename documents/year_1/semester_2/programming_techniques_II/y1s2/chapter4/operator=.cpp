#include<iostream>
#include<cstring>
using namespace std;
class PersonInfo{
    private:char*name;
    int age;
    public:
    PersonInfo(char *n,int a){//constructor
        name=new char[strlen(n)+1];
        strcpy(name,n);
        age=a;
    }
    PersonInfo(const PersonInfo &obj){//copy constructor
        name=new char[strlen(obj.name)+1];
        strcpy(name,obj.name);
        age=obj.age;
    }
    ~PersonInfo(){
        delete[]name;
    }
    const char *getName() const{
        return name;
    }
    int getAge(){
        return age;
    }
    void operator=(const PersonInfo&right){//Overloaded=operator
        delete[]name;
        name=new char[strlen(right.name)+1];
        strcpy(name,right.name);
        age=right.age;
    }
};

int main(){

    PersonInfo person1("Molly Mcbridge",27);
    PersonInfo person2=person1;

    return 0;
}