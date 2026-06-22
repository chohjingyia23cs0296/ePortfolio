#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // Overload operator+ to add two MyClass objects
    MyClass* operator+(const MyClass& other) {
        value += other.value;
        return this; // Return pointer to the object itself
    }

    // Overload operator- to subtract two MyClass objects
    MyClass* operator-(const MyClass& other) {
        value -= other.value;
        return this; // Return pointer to the object itself
    }

    // Function to display the value of MyClass object
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(3);

    // Add obj2 to obj1 and assign result to obj1
    obj1 + obj2;
    cout << "After addition: ";
    obj1.display();

    // Subtract obj2 from obj1 and assign result to obj1
    obj1 - obj2;
    cout << "After subtraction: ";
    obj1.display();

    return 0;
}
