#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
class Array{
    private:
    vector<T> items;
    public:
    void add(const T&item){
        items.push_back(item);
    }
    T getItem(int index)const{
        if(index<0||index>=items.size()){
            throw "Index out of bound";
        }
        return items[index];
    }
    void print(){
        for(const auto item:items){
            cout<<item<<endl;
        }
    }
};
class Name{
    private:
    string firstName;
    string lastName;
    public:
    Name(string fN,string lN):firstName(fN),lastName(lN){};
    friend ostream& operator<<(ostream&os,const Name&name){
        os<<"First name:"<<name.firstName<<"\nLast name: "<<name.lastName<<"\n";
        return os;
    }
};
class Instructor{
    private:
    Name name;
    string officenumber;
    public:
    Instructor(string officenum,string fN,string lN):name(fN,lN){
        officenumber=officenum;
    }
    friend ostream&operator<<(ostream&os,const Instructor&instructor){
        os<<"Instructor Information:\n";
        os<<instructor.name<<"Office number: "<<instructor.officenumber<<endl;
        return os;
    }
};
class TextBook{
    private:
    string title;
    string author;
    string publisher;
    public:
    TextBook(string t,string a,string p):title(t),author(a),publisher(p){};
    friend ostream& operator<<(ostream& os, const TextBook& textbook) {
        os << "Title: " << textbook.title << "\nAuthor: " << textbook.author << "\nPublisher: " << textbook.publisher << endl;
        return os;
    }
};
class Course{
    private:
    Instructor instructor;
    TextBook textbook;
    string title;
    public:
    Course(string t,Instructor i,TextBook text):instructor(i),textbook(text){
        title=t;
    }
    friend ostream&operator<<(ostream&os,Course& course){
        os<<"Course name: "<<course.title<<endl;
        os<<course.instructor;
        os<<course.textbook;
        return os;
    }
};
int main(){
    
    Array<Instructor> instructorArray;
    Array<TextBook> TextbookArray;

    instructorArray.add(Instructor("N28-L305","Ahmad","Kamal"));
    instructorArray.add(Instructor("D06-105","Mellisa","Wong"));
    instructorArray.add(Instructor("N28A-L501","Ali","Hassan"));
    
    cout << "LIST OF INSTRUCTORS:\n" << endl;
    instructorArray.print();
    cout << "-------------------------------------------------------------" << endl;
    
    TextbookArray.add(TextBook("Object-Oriented Programming Approached Using C++","Gilberg","Springer Publication"));
    TextbookArray.add(TextBook("Introdcution to Functional Programming with TypeScript","Samantha","Oxford Press"));

    // Printing textbooks
    cout << "LIST OF TEXTBOOKS:\n" << endl;
    TextbookArray.print();
    cout << "-------------------------------------------------------------" << endl;

    Course course("Programming Technique II",instructorArray.getItem(1),TextbookArray.getItem(0));
    cout << "COURSE INFORMATION:\n" << endl;
    cout << course;
    return 0;

}