#include<iostream>
#include<string>

using namespace std; 

class Student {
private:
    string studName;
    int studId;

};

class Professor {
private:
    int numOfTeaching;
    string profName;
public:
    Professor(string name) {
        profName=name;
        numOfTeaching=0; 
    }
    string display() {
        return "Professor Name: " + profName + ", Number of Teachings: " + to_string(numOfTeaching);
    }
    ~Professor(){

    }
};

class College {
private:
    string name;
    Professor *prof;
    Student stud;
public:
    College(string collegeName, Professor *professor) {
        name=collegeName;
        prof=professor; 
    }
    ~College(){

    }
};
