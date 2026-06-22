#include<iostream>
#include "Rectangle.h"
#include "Rectangle.cpp"
using namespace std;

int main(){

    Rectangle r;
    double getlength,getwidth;
    cout<<"Enter length: ";
    cin>>getlength;
    cout<<"Enter width: ";
    cin>>getwidth;
    r.setLength(getlength);
    r.setWidth(getwidth);

    cout<<"Here is the information"<<endl;
    cout<<"Length: "<<r.getLength()<<endl;
    cout<<"Width: "<<r.getWidth()<<endl;
    cout<<"Area: "<<r.getArea()<<endl;

    return 0;
}