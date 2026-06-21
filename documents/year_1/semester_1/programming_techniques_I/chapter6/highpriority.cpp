#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    double number = 123.456789;

    // setprecision has high priority
    cout << "setprecision(3): " << setprecision(3) << number << endl;//123

    // showpoint has high priority
    cout << "showpoint: " << showpoint << number << endl;//123.

    // fixed has lower priority than setprecision and showpoint
    cout << "fixed: " << fixed << number << endl;//123.457

    // setw has lower priority than setprecision, showpoint, and fixed
    cout << "setw(10): " << setw(10) << number << endl;//   123.457

    // left and right have the lowest priority
    cout << "left: " << left << setw(10) << number << endl;//123.457
    cout << "right: " << right << setw(10) << number << endl;//   123.457

     /*
setprecision has a high priority as it sets the number of digits to be displayed after the decimal point for 
floating-point numbers.

The showpoint manipulator also has a high priority as it ensures that the decimal point and trailing zeros 
are always displayed for floating-point numbers.

The fixed manipulator sets the floating-point notation to fixed, and it has a priority lower than setprecision 
and showpoint.

The setw manipulator has a lower priority as it sets the field width for the next output operation, affecting
 only the next output item.

The left and right manipulators have a lower priority as they set the justification of the output within
 the specified field width, affecting the alignment of all subsequent output.*/

     return 0;
}