#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload operator+ to add two complex numbers
    Complex* operator+(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return this; // Return pointer to the object itself
    }

    // Overload operator- to subtract two complex numbers
    Complex* operator-(const Complex& other) {
        real -= other.real;
        imag -= other.imag;
        return this; // Return pointer to the object itself
    }

    // Function to display the complex number
    void display() const {
        cout << "Real part: " << real << ", Imaginary part: " << imag << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    // Add c2 to c1 and assign result to c1
    c1 + c2;
    cout << "After addition: ";
    c1.display();

    // Subtract c2 from c1 and assign result to c1
    c1 - c2;
    cout << "After subtraction: ";
    c1.display();

    return 0;
}
