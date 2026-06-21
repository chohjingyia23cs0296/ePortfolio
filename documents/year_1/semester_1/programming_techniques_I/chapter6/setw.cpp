#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float x= 23.12767, y = 1345.4567, z = 866.887234, q = 2.34;
    cout << setprecision(4) << x << endl;//23.13
    cout << setprecision(5) << x << endl;//23.128
    cout << setprecision(2) << x << endl;//23
    cout << fixed<<setprecision(2) ;//space two blank
    cout << setw(7)<<x<<endl;//23.13
    cout << setw(7)<<y<<endl;//1345.46
    cout << setw(7)<<z<<endl;// 866.89
    cout << fixed<<showpoint;
    cout<<setprecision(1) ;
    cout << x<< endl<<y<<endl<< z<<endl;//23.1//1345.5//866.9

    cout<<setprecision(6) ;
    cout<<q<<endl;//2.340000
    cout<<showpoint<<q<<endl;//2.340000

 return 0; }