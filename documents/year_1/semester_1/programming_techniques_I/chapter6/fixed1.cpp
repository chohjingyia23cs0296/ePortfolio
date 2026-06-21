#include <iostream>
using namespace std;
int main()
{
float small = 3.1415926535897932384626;
float large = 6.0234567e17;
float whole = 2.000000000;
cout << "Some values in general format" << endl;
cout << "small: " << small << endl;
cout << "large: " << large << endl;
cout << "whole: " << whole << endl << endl;
cout << fixed;
cout << "The same values in fixed format" << endl;
cout << "small: " << small << endl;
cout << "large: " << large << endl;
cout << "whole: " << whole << endl << endl;
return 0;
}