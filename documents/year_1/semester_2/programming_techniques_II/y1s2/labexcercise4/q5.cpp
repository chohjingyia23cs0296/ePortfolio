#include <iostream>
using namespace std;

template <typename T>
T square(T number) {
    return number * number;
}

int main() {
    int intResult = square(4);        
    float floatResult = square(4.5f); 
    double doubleResult = square(4.5);

    cout << "Square of 4 (int): " << intResult << endl;
    cout << "Square of 4.5 (float): " << floatResult << endl;
    cout << "Square of 4.5 (double): " << doubleResult << endl;

    return 0;
}
