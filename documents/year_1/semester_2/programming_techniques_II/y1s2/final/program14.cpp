#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Array{
    private:
    vector<T>itemList;
    public:
    void add(const T& item){
        itemList.push_back(item);
    }
    T getItem(int index){
        return itemList[index];
    }
    void print(){
        for(auto itemlist:itemList)
        itemlist.print();
    }
};
class TextBook{
    private:
    string title;
    string author;
    string publisher;
    public:
    TextBook(string t,string a,string p):title(t),author(a),publisher(p){};
    void print(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl<<endl;
    }

};
class Instructor{
    private:
    string firstName;
    string lastName;
    string officenum;
    
    public:
    Instructor(string fN,string lN,string office):firstName(fN),lastName(lN),officenum(office){};
    void print(){
        cout<<"Firstname:"<<firstName<<endl;
        cout<<"Last name: "<<lastName<<endl;
        cout<<"Office number: "<<officenum<<endl;
       
    }
};
class Course{
    private:
    string name;
    TextBook*textbook;
    Instructor*instructor;

    public:
    Course(string n="Programming Technique II"):textbook(NULL),instructor(NULL),name(n){};
    void setTextBook(TextBook*t){
        textbook=t;
    }
    void setInstructor(Instructor*i){
        instructor=i;
    }
    void print(){
        
        cout<<"COURSE INFORMATION:\n\n";
        cout<<"Course Name :"<<name<<endl;
        cout<<"instructor information\n";
        if(instructor)
        instructor->print();
        cout<<"\n";
        cout<<"Textbook Information:\n";
        if(textbook)
        textbook->print();
        
    }

};


int main(){
    Array<Instructor>instructoradd;
    Array<TextBook>textbookadd;
    instructoradd.add(Instructor("Ahmad","Kamal","N28-L305"));
    instructoradd.add(Instructor("Mellisa","Wong","D06-105"));
    instructoradd.add(Instructor("Ahmad","Kamal","N28A-L501"));
    cout<<"LIST OF INSTRUCTORS:\n\n";
    instructoradd.print();
    textbookadd.add(TextBook("Object-Oriented Programming Approach Using C++","Gilberg","Springer Publication"));
    textbookadd.add(TextBook("Introduction to Functional Programming with TypeScript","Samantha","Oxford Press"));
    cout<<"LIST OF TEXTBOOKS:\n\n";
    textbookadd.print();
    Course course("Programming Technique II");
    course.setInstructor(new Instructor("Mellisa","Wong","D06-105"));
    course.setTextBook(new TextBook("Object-Oriented Programming Approach Using C++","Gilberg","Springer Publication"));
    
    course.print();



    
}

