#include"Rectangle.h"
#include"Rectangle.cpp"
#include<iostream>
using namespace std;

int main(){
    int width;
    int length;
    Rectangle myRectangle;
    cout<<"Enter the rectangle's width: ";
    cin>>width;
    cout<<"Enter the rectangle's length: ";
    cin>>length;

    try{
        myRectangle.setLength(length);
        myRectangle.setWidth(width);
        cout<<"The area of the rectangle is"
        <<myRectangle.getArea()<<"\n";
    }
    catch(Rectangle::NegativeSize){
        cout<<"Error: A negative value was entered.\n";

    }
    cout<<"End of a a program.\n";
    return 0;
}