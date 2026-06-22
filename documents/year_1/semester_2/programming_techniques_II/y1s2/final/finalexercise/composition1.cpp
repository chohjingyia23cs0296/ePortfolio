#include<iostream>
using namespace std;

class Person{
    private:
    string name;

    public:
    Person(string n){
        name=n;
    }
    string getName(){
        return name;
    }
};
class Textbook{
    private:
    Person person;
    string title;
    public:
    Textbook(string t,string n):title(t),person(n){};
    void print(){
        cout<<"TextBook: "<<title<<endl;
        cout<<"Person: "<<person.getName()<<endl;
    }
};
class Course{
    private:
    string CourseName;
    Person person;
    Textbook textbook;

    public:
    Course(string cN,string n,string textbookName,string textbooktitle):CourseName(cN),person(n),textbook(textbookName,textbooktitle){};
    void print(){
        cout<<"Course Name: "<<CourseName<<endl;
        cout<<"Instructor: "<<person.getName()<<endl;
        textbook.print();
    }
};
int main(){
    Course course("PT2","Jing yi","Harry","Potter");
    course.print();
}