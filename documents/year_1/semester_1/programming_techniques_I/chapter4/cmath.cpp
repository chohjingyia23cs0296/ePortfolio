#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.14159
int main(){
    double area,radius;
    cout<<"What is the radius of circle: ";
    cin>>radius;
    area=  PI * pow(radius,2.0);
    cout<<"The area of circle is "<<area<<endl;
    return 0;
}