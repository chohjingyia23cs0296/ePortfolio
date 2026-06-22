//Program 10.4
#include<iostream>
using namespace std;

template <typename T>
class calc {
public:
    T multiply(T x, T y);
    T add(T x, T y);
};

template <typename T>
T calc<T>::multiply(T x, T y) {
    return x * y;
}

template <typename T>
T calc<T>::add(T x, T y) {
    return x + y;
}

int main() {
    calc<int> intCalc;
    calc<float> floatCalc;
    calc<double> doubleCalc;

    // Test the calc class with integer values
    int intResult1 = intCalc.multiply(4, 2);
    int intResult2 = intCalc.add(4, 2);
    cout << "Integer multiplication: 4 * 2 = " << intResult1 << endl;
    cout << "Integer addition: 4 + 2 = " << intResult2 << endl;

    // Test the calc class with float values
    float floatResult1 = floatCalc.multiply(4.5f, 2.5f);
    float floatResult2 = floatCalc.add(4.5f, 2.5f);
    cout << "Float multiplication: 4.5 * 2.5 = " << floatResult1 << endl;
    cout << "Float addition: 4.5 + 2.5 = " << floatResult2 << endl;

    // Test the calc class with double values
    double doubleResult1 = doubleCalc.multiply(4.5, 2.5);
    double doubleResult2 = doubleCalc.add(4.5, 2.5);
    cout << "Double multiplication: 4.5 * 2.5 = " << doubleResult1 << endl;
    cout << "Double addition: 4.5 + 2.5 = " << doubleResult2 << endl;

    return 0;
}