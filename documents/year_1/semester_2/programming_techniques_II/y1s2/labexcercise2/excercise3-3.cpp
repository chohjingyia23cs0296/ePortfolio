#include <iostream>
using namespace std;


class BasicShape {
protected:
    double area;

public:

    BasicShape() : area(0.0) {}

    double getArea() const {
        return area;
    }

    virtual void calcArea() = 0;
};


class Circle : public BasicShape {
private:
    double radius;
    long centerX;
    long centerY;

public:

    Circle(long x, long y, double r) : radius(r), centerX(x), centerY(y) {
        calcArea(); 
    }

    long getCenterX() const {
        return centerX;
    }

    long getCenterY() const {
        return centerY;
    }

    void calcArea() override {
        area = 3.14159 * radius * radius;
    }
};

class Rectangle : public BasicShape {
private:
    long width;
    long length;

public:

    Rectangle(long w, long l) : width(w), length(l) {
        calcArea();
    }

    long getWidth() const {
        return width;
    }

    long getLength() const {
        return length;
    }

    void calcArea() override {
        area = length * width;
    }
};

int main() {
    Circle circle(0, 0, 6.0);
    Rectangle rectangle(4, 6);
    cout << "Area of Circle: " << circle.getArea() << endl;

    cout << "Area of Rectangle with width " << rectangle.getWidth()
         << " and length " << rectangle.getLength() << " is " << rectangle.getArea()<< endl;

    return 0;
}
