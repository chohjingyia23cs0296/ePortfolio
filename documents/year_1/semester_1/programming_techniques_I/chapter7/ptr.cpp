#include <iostream>
using namespace std;
int main()
{
int x=25;

int *ptr=&x;

cout<<"here is the values in printed twice:\n";
cout<<x<<endl;
cout << ptr << endl;

*ptr=100;
cout<<"here is the values in printed twice:\n";
cout<<x<<endl;
cout << *ptr << endl;

}