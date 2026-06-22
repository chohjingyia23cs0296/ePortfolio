#include <iostream>
using namespace std;

// Define the Circle class
class Circle {
public:
    int width;
    int length;

    // Constructor
    Circle(int w, int l) : width(w), length(l) {}
};

// Function to modify Circle attributes using call by value
void modifyByValue(Circle c) {
    c.width = 10; // Modify width
    c.length = 20; // Modify length
}

// Function to modify Circle attributes using call by pointer
void modifyByPointer(Circle* c) {
    c->width = 30; // Modify width
    c->length = 40; // Modify length
}

// Function to modify Circle attributes using call by reference
void modifyByReference(Circle& c) {
    c.width = 50; // Modify width
    c.length = 60; // Modify length
}

int main() {
    // Create a Circle object
    Circle myCircle(5, 15);

    // Call modifyByValue
    modifyByValue(myCircle);
    cout << "Modified attributes (by value): width = " << myCircle.width << ", length = " << myCircle.length << endl;

    // Call modifyByPointer
    modifyByPointer(&myCircle);
    cout << "Modified attributes (by pointer): width = " << myCircle.width << ", length = " << myCircle.length << endl;

    // Call modifyByReference
    modifyByReference(myCircle);
    cout << "Modified attributes (by reference): width = " << myCircle.width << ", length = " << myCircle.length << endl;

    return 0;
}
