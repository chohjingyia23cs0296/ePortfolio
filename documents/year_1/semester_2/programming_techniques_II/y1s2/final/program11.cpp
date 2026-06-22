#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Array{
    private:
    vector<T> itemlist;
    public:
    void add(const T&item){
        itemlist.push_back(item);
    }
    T getItem(int index){
        if(index<0||index>=itemlist.size()){
            throw "error";
        }
        return itemlist[index];
    }

    void print(){
        for(const auto&item:itemlist){
            item.print();
        }
    }
};
class Instructor{
    private:
    string firstname;
    string lastname;
    string officenum;
    public:
    Instructor(string fN,string lN,string office):firstname(fN),lastname(lN),officenum(office){};
    void print()const{
        cout<<"First name: "<<firstname<<endl;
        cout<<"Last name: "<<lastname<<endl;
        cout<<"Office number: "<<officenum<<endl<<endl;
         
    }


};
class TextBook{
    private:
    string author;
    string publisher;
    string title;
    public:
    TextBook(string a,string p,string t):author(a),publisher(p),title(t){};
    void print()const{
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl<<endl;
         
    }

};
class Course {
    private:
        Instructor instructor;
        TextBook textbook;
        string coursename;

    public:
        Course(string c, Instructor i, TextBook t)
            : coursename(c), instructor(i), textbook(t) {}
        
        void print()const{
            cout << "Course: " << coursename << endl;
            cout<<"Instructor Information:\n";
            instructor.print();
            cout << "Textbook Information:" << endl;
            textbook.print();

        }
};
int main(){
    Array<Instructor>instructor;
    Array<TextBook>textbook;
    instructor.add(Instructor("Ahmad","Kamal","N28-L305"));
    instructor.add(Instructor("Mellisa","Wong","D06-105"));
    instructor.add(Instructor("Ali","Hassan","N28A-L501"));

    textbook.add(TextBook("Object-Oriented Programming Approached Using C++","Gilberg","Springer Publication"));
    textbook.add(TextBook("Introdcution to Functional Programming with TypeScript","Samantha","Oxford Press"));
   

    cout<<"LIST OF INSTRUCTORS:\n\n";
    instructor.print();
    cout<<"LIST OF TEXTBOOKS\n\n";
    textbook.print();
    // Creating and printing a course
    Instructor courseInstructor("Mellisa", "Wong", "D06-105");
    TextBook courseTextbook("Object-Oriented Programming Approach Using C++", "Gilberg", "Springer Publication");
    Course course("Programming Technique II", courseInstructor, courseTextbook);

    cout << "COURSE INFORMATION:\n\n";
    course.print();

}