#include <iostream>

// Circle class declaration
class Circle {
public:
    int width;  // Public member
    int length; // Public member

    Circle(int w,int l){
        width=w;
        length=l;
    }
private:
    // Private member function
    double calculateArea() const {
        return 3.14159 * width * length;
    }

    // Declare the friend function
    friend void printArea(const Circle& circle);
};

// Friend function definition
void printArea(const Circle& circle) {
    // Accessing private member function
    double area = circle.calculateArea();
    std::cout << "Area of the circle: " << area << std::endl;
}

int main() {
    // Create a Circle object
    Circle circle(5, 5);

    // Access public members directly
    std::cout << "Width: " << circle.width << ", Length: " << circle.length << std::endl;

    // Access private member function using friend function
    printArea(circle);

    return 0;
}
