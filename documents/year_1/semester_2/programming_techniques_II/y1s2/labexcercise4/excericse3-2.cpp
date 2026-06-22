#include <iostream>
using namespace std;

template <typename T>
T absoluteValue(T number1, T number2) {
    if(number1<0)
    number1=-number1;
    else
    number1=number1;
    
    if(number2<0)
    number2=-number2;
    else
    number2=number2;
    return number1+number2; 
}

int main() {
    
    int intVal1 = -5, intVal2 = 3;
    float floatVal1 = -3.14f, floatVal2 = 2.71f;
    double doubleVal1 = -2.718, doubleVal2 = 1.414;
    char charVal1 = -100, charVal2 = 50;

    cout << "Sum of absolute values (int): " << absoluteValue(intVal1, intVal2) << endl;
    cout << "Sum of absolute values (float): " << absoluteValue(floatVal1, floatVal2) << endl;
    cout << "Sum of absolute values (double): " << absoluteValue(doubleVal1, doubleVal2) << endl;
    cout << "Sum of absolute values (char): " << static_cast<int>(absoluteValue(charVal1, charVal2)) << endl;

    return 0;
}
