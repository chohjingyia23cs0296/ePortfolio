#include<iostream>
#include<cstdlib>
#include "Rectangle.h"
using namespace std;

void Rectangle::setLength(double len){
    length=len;
}
void Rectangle::setWidth(double w){
    width=w;
}
double Rectangle::getLength()const{
    return length;
}
double Rectangle::getWidth()const{
    return width;
}
double Rectangle::getArea()const{
    return length*width;
}
