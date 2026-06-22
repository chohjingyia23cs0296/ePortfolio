#include <iostream>
using namespace std;

int main()
{
     short numbers[]={10,20,30,40,50};

     cout<<"the first element of the array is: \n";
     cout<<*(numbers+2)<<endl;

     return 0;
}