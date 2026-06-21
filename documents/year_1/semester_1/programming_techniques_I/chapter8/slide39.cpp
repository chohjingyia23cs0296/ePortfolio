#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI=3.14159;
struct Circle{
    double radius;
    double diameter;
    double area;
};
Circle getInfo();
Circle displayInfo(Circle c);
int main(){
    Circle c;
    c=getInfo();
    c.area=PI*pow(c.radius,2.0);
    displayInfo( c);

    return 0;
}
Circle getInfo(){
    Circle tempCircle;
    cout<<"Enter the diamter of a circle: ";
    cin>>tempCircle.diameter;
    tempCircle.radius=tempCircle.diameter/2;
    return tempCircle;
}
Circle displayInfo(Circle c){
    cout<<"Theradius and area of the circle are: \n";
    cout<<fixed<<setprecision(2);
    cout<<"Radius : "<<c.radius<<endl;
    cout<<"Area: "<<c.area<<endl;
}
