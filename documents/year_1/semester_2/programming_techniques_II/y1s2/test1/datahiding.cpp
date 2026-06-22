//Data hiding ensure methods should not directly access instance attributes in a class other than their own
#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;
public:
    // Constructor to initialize private member variables
    Person(const string& _name, int _age) : name(_name), age(_age) {}
 // Public member function to access name
    string getName() const {
        return name;
    }
    // Public member function to access age
    int getAge() const {
        return age;
    }
    // Public member function to update age
    void setAge(int newAge) {
        age = newAge;
    }
};
int main() {
    // Create a Person object
    Person person("Alice", 30);
    // Access and display the person's name and age
    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;
    // Update the person's age
    person.setAge(35);
    // Display the updated age
    cout << "Updated Age: " << person.getAge() << endl;

    return 0;
}
