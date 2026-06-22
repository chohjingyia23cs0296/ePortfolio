#include<iostream>
#include <cstring>
using namespace std;

class PersonInfo {
private:
    char* name;
    int age;

public:
    // Constructors
    PersonInfo(const char* n = "", int a = 0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }

    // Copy Constructor
    PersonInfo(const PersonInfo& right) {
        name = new char[strlen(right.name) + 1];
        strcpy(name, right.name);
        age = right.age;
    }

    // Destructor
    ~PersonInfo() {
        delete[] name;
    }

    // Getter methods
    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Copy Assignment Operator
    PersonInfo& operator=(const PersonInfo& right) {
        if (this != &right) { // Self-assignment check
            delete[] name;
            name = new char[strlen(right.name) + 1];
            strcpy(name, right.name);
            age = right.age;
        }
        return *this;
    }
};

int main() {
    // Create a PersonInfo object
    PersonInfo person1("Molly McBride", 27);
    
    // Use the copy assignment operator
    PersonInfo person2, person3;
    person2 = person2 = person1;

    // Test by displaying information
    cout << "Person 1: Name: " << person1.getName() << ", Age: " << person1.getAge() << endl;
    cout << "Person 2: Name: " << person2.getName() << ", Age: " << person2.getAge() << endl;
    cout << "Person 3: Name: " << person3.getName() << ", Age: " << person3.getAge() << endl;

    return 0;
}
