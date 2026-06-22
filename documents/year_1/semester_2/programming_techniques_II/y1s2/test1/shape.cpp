#include <iostream>
using namespace std;

// Define the Shape class
class Shape {
public:
    double calc; // Member variable

    // Constructor
    Shape(double c) : calc(c) {}
};

// Function to modify calc member variable using call by value
void modifyByValue(Shape s) {
    s.calc = 10.0; // Modify calc
}

// Function to modify calc member variable using call by pointer
void modifyByPointer(Shape* s) {
    s->calc = 20.0; // Modify calc
}

// Function to modify calc member variable using call by reference
void modifyByReference(Shape& s) {
    s.calc = 30.0; // Modify calc
}

int main() {
    // Create a Shape object
    Shape myShape(5.0);

    // Call modifyByValue
    modifyByValue(myShape);
    cout << "Modified calc (by value): " << myShape.calc << endl;

    // Call modifyByPointer
    modifyByPointer(&myShape);
    cout << "Modified calc (by pointer): " << myShape.calc << endl;

    // Call modifyByReference
    modifyByReference(myShape);
    cout << "Modified calc (by reference): " << myShape.calc << endl;

    return 0;
}
