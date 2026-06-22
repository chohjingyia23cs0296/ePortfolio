#include <iostream>
#include <string>
using namespace std;

// Base class Transport
class Transport {
protected:
    string name;
    string year;

public:
    // Constructor
    Transport(string n = "", string y = "") : name(n), year(y) {}

    // Accessors and Mutators
    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setYear(string y) {
        year = y;
    }

    string getYear() const {
        return year;
    }

    virtual void print() const {
        cout << "Transport Name: " << name << ", Year Built: " << year << endl;
    }

    virtual ~Transport() {}
};

class Car : public Transport {
private:
    int maxPassengers;

public:
    // Constructor
    Car(string n = "", string y = "", int p = 0) : Transport(n, y), maxPassengers(p) {}

    // Accessors and Mutators
    void setMaxPassengers(int p) {
        maxPassengers = p;
    }

    int getMaxPassengers() const {
        return maxPassengers;
    }

    // Override print function
    void print() const override {
        cout << "Car Name: " << name << ", Max Passengers: " << maxPassengers << endl;
    }
};

// Derived class Motor
class Motor : public Transport {
private:
    int maxPassengers;

public:
    // Constructor
    Motor(string n = "", string y = "", int p = 0) : Transport(n, y), maxPassengers(p) {}

    // Accessors and Mutators
    void setMaxPassengers(int p) {
        maxPassengers = p;
    }

    int getMaxPassengers() const {
        return maxPassengers;
    }

    // Override print function
    void print() const override {
        cout << "Motor Name: " << name << ", Max Passengers: " << maxPassengers << endl;
    }
};

int main() {

    Transport* transports[3];

    transports[0] = new Transport("Generic Transport", "2020");
    transports[1] = new Car("Family Car", "2019", 5);
    transports[2] = new Motor("Sport Motor", "2021", 2);

    for (int i = 0; i < 3; ++i) {
        transports[i]->print();
    }
 
    for (int i = 0; i < 3; ++i) {
        delete transports[i];
    }

    return 0;
}
