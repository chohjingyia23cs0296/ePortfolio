//Composition is a restrcited vision of aggregation in which the wnclosing and enclose object 
//are highlt dependent on each other
#include <iostream>
#include <string>

using namespace std;

// Contained class
class Engine {
private:
    int horsepower;
public:
    Engine(int power) : horsepower(power) {}
    void start() {
        cout << "Engine started. Power: " << horsepower << "hp" << endl;
    }
};

// Containing class
class Car {
private:
    string model;
    Engine engine; // Composition
public:
    Car(const string& carModel, int m) : model(carModel), engine(m) {}
    void drive() {
        cout << "Driving " << model << endl;
        engine.start();
    }
};

int main() {
    Car myCar("Toyota Camry", 200);
    myCar.drive();

    return 0;
}