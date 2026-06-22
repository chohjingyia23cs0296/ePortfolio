#include <iostream>
using namespace std;
int main()
{
float lots = 3.1415926535, little1 = 2.25;
float little2 = 1.5, whole = 4.00000;
cout << "Some values with noshowpoint (the default)" << endl;
cout << "lots: " << lots << endl;
cout << "little1: " << little1 << endl;
cout << "little2: " << little2 << endl;
cout << "whole: " << whole << endl << endl;
cout << "The same values with showpoint" << endl;
cout << showpoint;
cout << "lots: " << lots << endl;
cout << "little1: " << little1 << endl;
cout << "little2: " << little2 << endl;
cout << "whole: " << whole << endl;
return 0;
}