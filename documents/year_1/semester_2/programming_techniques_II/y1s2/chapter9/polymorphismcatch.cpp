#include <iostream>
using namespace std;

// Rename custom exception class to avoid conflicts
class MyException {
public:
    MyException() noexcept {}
    MyException(const MyException&) noexcept {}
    MyException& operator=(const MyException&) noexcept {}
    virtual ~MyException() noexcept {}
    virtual const char* what() const noexcept {
        return "Custom exception";
    }
};

class DividebyZero : public MyException {
public:
    const char* what() const noexcept override {
        return "Division by zero";
    }
};

double divide(double a, double b) {
    DividebyZero e;
    if (b == 0)
        throw e;
    return a / b;
}

int main() {
    double a, b, c;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    try {
        c = divide(a, b);
        cout << "The answer is " << c << endl;
    }
    catch (const MyException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
