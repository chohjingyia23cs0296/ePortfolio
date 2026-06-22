//association relate classes to each other through their objects
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
public:
    Student(const string& _name) : name(_name) {}

    string getName() const {
        return name;
    }
};
class School {
private:
    Student student;

public:
    School(const Student& _student) : student(_student) {}

    void displayStudent() const {
        cout << "Student name: " << student.getName() << endl;
    }
};
int main() {
    // Create a Student object
    Student student("Alice");
    // Create a School object and associate it with the Student object
    School school(student);
    // Display the associated student's name
    school.displayStudent();

    return 0;
}