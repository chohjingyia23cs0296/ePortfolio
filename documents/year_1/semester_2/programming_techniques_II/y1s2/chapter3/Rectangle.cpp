#include<iostream>
#include<cstdlib>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(){
    width=0.0;
    length=0.0;
}
void Rectangle::setLength(double len){
    if(len>=0){
        length=len;
    }else{
        cout<<"Invalid length.";
        exit(EXIT_FAILURE);
    }
}
void Rectangle::setWidth(double w){
    if(w>=0){
        width=w;
    }else{
        cout<<"Invalid width.";
        exit(EXIT_FAILURE);
    }
}

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

