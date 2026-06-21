#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
double x = 156.74, y = 235.765, z = 9525.9874;
cout << setprecision(5) << x << endl;//156.74
cout << setprecision(3) << x << endl;//157
cout << setprecision(2) << x << endl;//1.6e+002
cout << setprecision(1) << x << endl;//2e+002
cout << fixed << setprecision(2);
cout << x << endl << y << endl << z << endl;
return 0;
}