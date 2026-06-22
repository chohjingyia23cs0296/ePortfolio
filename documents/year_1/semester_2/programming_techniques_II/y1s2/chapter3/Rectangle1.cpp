#include<iostream>
#include<cstdlib>
#include "Rectangle1.h"
using namespace std;

Rectangle::Rectangle(double len, double w) {
    setLength(len);
    setWidth(w);
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

    
    double getlength,getwidth;
    cout<<"Enter length: ";
    cin>>getlength;
    cout<<"Enter width: ";
    cin>>getwidth;
    
    Rectangle r(getlength,getwidth);
    
    cout<<"Here is the information"<<endl;
    cout<<"Length: "<<r.getLength()<<endl;
    cout<<"Width: "<<r.getWidth()<<endl;
    cout<<"Area: "<<r.getArea()<<endl;

    return 0;
}