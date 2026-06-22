#include <iostream>
#include <string>

using namespace std;

// Base class Car
class Car {
public:
    // Method to start the car
    void start() const {
        cout << "Starting the car" << endl;
    }
};

// Derived class ElectricCar
class ElectricCar : public Car {
public:
    // Method to start the electric car
    void start() const {
        cout << "Starting the electric car" << endl;
    }
};

// Derived class GasolineCar
class GasolineCar : public Car {
public:
    // Method to start the gasoline car
    void start() const {
        cout << "Starting the gasoline car" << endl;
    }
};

int main() {
    ElectricCar eCar;
    GasolineCar gCar;

    // Polymorphic behavior: calling start() method on different objects
    eCar.start(); // Output: "Starting the electric car"
    gCar.start(); // Output: "Starting the gasoline car"

    return 0;
}
