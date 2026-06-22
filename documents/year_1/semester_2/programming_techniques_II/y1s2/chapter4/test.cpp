#include<iostream>
#include<cstring>
using namespace std;
class PersonInfo{

    private:
    char*name;
    int age;
    public:
    PersonInfo(char*n,int a){
        name=new char[strlen(n)+1];
        strcpy(name,n);
        age=a;
    }
    PersonInfo(const PersonInfo &obj){
        name=new char[strlen(obj.name)+1];
        strcpy(name,obj.name);
        age=obj.age;

    }
    ~PersonInfo(){
        delete[]name;
    }
    const char*getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    void operator=(const PersonInfo &right){
        name=new char[strlen(right.name)+1];
        strcpy(name,right.name);
        age=right.age;
    }
};
int main(){
    PersonInfo person1("Ali",27);
    PersonInfo person2=person1;
    
    return 0;
}
