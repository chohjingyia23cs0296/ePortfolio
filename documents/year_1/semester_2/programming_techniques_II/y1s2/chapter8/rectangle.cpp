#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;  // Pure virtual method
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override {
        return width * height;
    }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 5);

    cout << "Circle area: " << s1->area() << endl;     // Calls Circle's area method
    cout << "Rectangle area: " << s2->area() << endl;  // Calls Rectangle's area method

    delete s1;
    delete s2;

    return 0;
}
