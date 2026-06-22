#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char *name;
    int age;

public:
    Person() {
        name = " ";
        age = 0;
    }

    Person(char *n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }

    Person(const Person &object) {
        name = new char[strlen(object.name) + 1];
        strcpy(name, object.name);
        age = object.age;
    }

    void display() {
        cout << "Name: " << name << " Age: " << age << endl; // Added space after "Age"
    }
};

int main() {
    Person person1("jingyi", 20);
    Person person2 = person1;

    person1.display();
    person2.display();

    return 0;
}


