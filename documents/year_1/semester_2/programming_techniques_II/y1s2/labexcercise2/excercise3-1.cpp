#include <iostream>
using namespace std;

#define PI 3.1415

// Task 1: Complete the definition of the parent class 'Object3D'.
// Allow two methods below to be polymorphic (i.e., make those methods to be virtual methods)
class Object3D {
public:
    Object3D() {}
    virtual void print() const = 0; // pure virtual method
    virtual double getVolume() const = 0; // pure virtual method
};

// Task 2: Complete the definition of the class 'Sphere'.
// Redefine the following methods accordingly.
class Sphere : public Object3D {
protected:
    double r;
public:
    Sphere(double _r = 0) : r(_r) {}
    void setRadius(double _r) { r = _r; }
    double getRadius() const { return r; }
    void print() const override { cout << "Sphere: r = " << r << endl; }
    double getVolume() const override { return (4 / 3.0) * PI * r * r * r; }
};

// Task 3: Complete the definition of the class 'Cylinder'.
// Redefine the following methods accordingly.
class Cylinder : public Object3D {
protected:
    double r, h;
public:
    Cylinder(double _r = 0, double _h = 0) : r(_r), h(_h) {}
    void setRadius(double _r) { r = _r; }
    void setHeight(double _h) { h = _h; }
    double getRadius() const { return r; }
    double getHeight() const { return h; }
    void print() const override { cout << "Cylinder: r = " << r << ", h = " << h << endl; }
    double getVolume() const override { return PI * r * r * h; }
};

// Task 4: Complete the definition of the class 'Cuboid'.
// Redefine the following methods accordingly.
class Cuboid : public Object3D {
protected:
    double w, l, h;
public:
    Cuboid(double _w = 0, double _l = 0, double _h = 0) : w(_w), l(_l), h(_h) {}
    void setWidth(double _w) { w = _w; }
    void setLength(double _l) { l = _l; }
    void setHeight(double _h) { h = _h; }
    double getWidth() const { return w; }
    double getLength() const { return l; }
    double getHeight() const { return h; }
    void print() const override { cout << "Cuboid: dimensions = " << w << " x " << l << " x " << h << endl; }
    double getVolume() const override { return w * l * h; }
};

int main() {
    // Task 5: Create an array of pointers of Object3D.
    Object3D* objects[5];

    // Task 6: Fill in the array with different types of objects, for example cuboids, spheres and cylinders.
    objects[0] = new Cuboid(10, 20, 30);
    objects[1] = new Cylinder(20, 20);
    objects[2] = new Sphere(10);
    objects[3] = new Cylinder(2,5);
    objects[4] = new Sphere(3);
    

    // Task 7: Print the information of all objects along with their volume
    for (int i = 0; i < 5; i++) {
        cout << "Object #" << (i + 1) << endl;
        objects[i]->print();
        cout << "Volume = " << objects[i]->getVolume() << endl;
        cout << endl;
    }

    // Task 8: Calculate and print the total volume of the objects
    double totalVolume = 0;
    for (int i = 0; i < 5; i++) {
        totalVolume += objects[i]->getVolume();
    }
    cout << "Total volume = " << totalVolume << endl;

    // Clean up dynamic memory
    for (int i = 0; i < 5; i++) {
        delete objects[i];
    }

    return 0;
}
