// Program 10.2
#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    cout << "\n Input any two numbers: ";
    cin >> num1 >> num2;

    try {
        if (num2 == 0) 
            throw 0;//(is type of int)
        else
        num3 = num1 / num2;
        
    } catch (int x) {
        cout << "\n Cannot divide number with zero";
    }
    /*
    when num1=4 and num2=2,num3=2.
    The try block is executed.
    The program checks if num2 is 0. Since num2 is 2, it does not throw an exception.it will divide num 1 with num2 
    */
   /*
    when num1=4 and num2=0,num3=2.
    The try block is executed.
    The program checks if num2 is 0. Since num2 is 0, it throws an exception.
    The catch block catches the exception (value 0 is caught as x).
    The program prints Cannot divide number by zero.
   */

    return 0;
}
