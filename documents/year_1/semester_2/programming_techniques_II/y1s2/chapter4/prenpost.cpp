#include <iostream>
using namespace std;

class FeetInches {
private:
    int feet;
    int inches;

    void simplify();

public:
    // Constructor
    FeetInches(int f = 0, int i = 0) : feet(f), inches(i) {}

    // Pre-increment operator (++obj)
    FeetInches operator++();

    // Post-increment operator (obj++)
    FeetInches operator++(int);

    // Getter methods
    int getFeet() const {
        return feet;
    }

    int getInches() const {
        return inches;
    }
};

// Member function definitions

void FeetInches::simplify() {
    if (inches >= 12) {
        feet += inches / 12;
        inches %= 12;
    }
}

FeetInches FeetInches::operator++() {
    ++inches;
    simplify();
    return *this;
}

FeetInches FeetInches::operator++(int) {
    FeetInches temp(feet, inches);
    ++inches;
    simplify();
    return temp;
}

int main() {
    // Create a FeetInches object
    FeetInches obj1(3, 11);
    
    // Display the initial value
    cout << "Initial value: " << obj1.getFeet() << " feet " << obj1.getInches() << " inches" << endl;
    
    // Test pre-increment operator
    ++obj1;
    cout << "After pre-increment: " << obj1.getFeet() << " feet " << obj1.getInches() << " inches" << endl;

    // Test post-increment operator
    FeetInches obj2 = obj1++;
    cout << "After post-increment: " << obj1.getFeet() << " feet " << obj1.getInches() << " inches" << endl;
    cout << "Post-incremented value (returned by post-increment operator): " << obj2.getFeet() << " feet " << obj2.getInches() << " inches" << endl;

    return 0;
}
