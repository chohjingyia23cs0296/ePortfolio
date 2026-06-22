// Exercise 4
// Programming Technique II
// Semester 2, 2023/2024
// Date: 27/6/2024  
// Section: 1  
// Member 1's Name: CHOH JING YI     
// Member 2's Name: LIOW JIA FENG 

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
public:
    Student(string _firstName, string _lastName) : firstName(_firstName), lastName(_lastName) {}
    void setName(string _firstName, string _lastName) {
        firstName = _firstName;
        lastName = _lastName;
    }
    void print() const {
        cout << "Student Name: " << firstName << " " << lastName << endl;
    }
};

class Lecturer {
private:
    string name;
public:
    Lecturer(string _name) : name(_name) {}
    void print() const {
        cout << "Lecturer Name: " << name << endl;
    }
};

class Course {
private:
    string courseName;
    Student* student; // Aggregation
    Lecturer* lecturer; // Association
public:
    Course(string _courseName, Student* student, Lecturer* lecturer) 
        : courseName(_courseName), student(student), lecturer(lecturer) {}
    void print() const {
        student->print();
        cout << "Course Name: " << courseName << endl;
        lecturer->print();
    }
};

class Department {
private:
    string departmentName;
    Course& course; // Composition
public:
    Department(string _departmentName, Course& course) 
        : departmentName(_departmentName), course(course) {}
    void print() const {
        cout << "Department Name: " << departmentName << endl;
        course.print();
    }
};

int main() {
    Student student1("Choh", "Jing Yi");
    Lecturer lecturer1("Liow Jia Feng");
    Course course1("PT2", &student1, &lecturer1);
    Department department1("Computer Science", course1);
    department1.print();

    return 0;
}