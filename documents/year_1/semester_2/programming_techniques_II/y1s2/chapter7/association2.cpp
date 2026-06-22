#include<iostream>
using namespace std;

class Course{
    private:
    string name;
    string code;
    int section;
    public:
    Course(string n,string c,int s):name(n),code(c),section(s){};
    string getName(){
        return name;
    }
};
class Lecturer{
    private:
    string name;
    Course *c;
    public:
    Lecturer(string n):name(n){};
    void teach(Course *subject){
        c=subject;
    }
    void display(){
        cout<<name<<"lectur "<<c->getName()<<endl;
    }

};
int main(){
    Course *c=new Course("Sofwtare","SECJ",1234);
    Lecturer lecturer("Hi");
    lecturer.teach(c);
    lecturer.display();
}