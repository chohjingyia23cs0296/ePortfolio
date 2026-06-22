#include <iostream>

class Rectangle {
    int height, width;
public:
    Rectangle(int a = 0, int b = 0) {
        height = b;
        width = a;
    }
    int getWidth() { return width; }
    int getHeight() { return height; }
    
    // Overloaded + operator function as a friend function
    friend Rectangle operator+(Rectangle r1, Rectangle r2) {
        Rectangle result;
        result.width = r1.width + r2.width;
        result.height = r1.height + r2.height;
        return result;
    }

    // Overloaded - operator function
    Rectangle operator-(Rectangle r) {
        Rectangle result;
        result.width = width - r.width;
        result.height = height - r.height;
        return result;
    }
};

int main() {
    Rectangle rect1(5, 10);
    Rectangle rect2(3, 7);
    
    Rectangle rect3 = rect1 + rect2; // Adding two rectangles
    Rectangle rect4 = rect1 - rect2; // Subtracting one rectangle from another
    
    std::cout << "Width of rect3: " << rect3.getWidth() << ", Height of rect3: " << rect3.getHeight() << std::endl;
    std::cout << "Width of rect4: " << rect4.getWidth() << ", Height of rect4: " << rect4.getHeight() << std::endl;

    return 0;
}
