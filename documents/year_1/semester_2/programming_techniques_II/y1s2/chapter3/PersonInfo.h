#ifndef PERSONINFO_H
#define PERSONINFO_H
#include<cstring>

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

    //Copy constructor
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

};
#endif