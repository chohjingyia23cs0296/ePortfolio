#include <iostream>

using namespace std;

class MyClass {
private:
    int x;

public:
    // Constructor
    MyClass(int x) {
        // Initialize the attribute x using the this pointer
        this->x = x;
    }

    // Method to set the value of x
    void setX(int x) {
        // Accessing the attribute x using the this pointer
        this->x = x;
    }

    // Method to increment the value of x and return the current object
    MyClass& increment() {
        // Incrementing the attribute x
        this->x++;
        // Return the current object
        return *this;
    }

    // Method to print the value of x
    void printX() const {
        cout << "Value of x: " << x << endl;
    }
};

int main() {
    // Create an object of MyClass
    MyClass obj(5);

    // Use the setX method to change the value of x
    obj.setX(10);

    // Increment the value of x using the increment method
    obj.increment().increment();

    // Print the final value of x
    obj.printX();

    return 0;
}
