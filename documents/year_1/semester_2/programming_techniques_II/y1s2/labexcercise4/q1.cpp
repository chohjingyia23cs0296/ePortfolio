//Program 10.1
#include<iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    cout << "Input any two numbers: ";
    cin >> num1 >> num2;
    num3 = num1 / num2;
    //when num1=4 and num2=2,num3=2 because 4 divide 2 result will be 2
    //when num2=4 and num2=0,num3=error, which is an illegal operation in C++. This causes a runtime error. 
    cout << num3;

    return 0;
}
