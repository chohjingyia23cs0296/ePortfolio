#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int x = 15;
int y = 7634;
cout<<left;
cout << setw(5) << x << setw(7) << y << setw(8) << "Warm"
<< endl;
cout << right;
cout << setw(5) << x << setw(7) << y << setw(8) << "Warm"
<< endl;
return 0;
}