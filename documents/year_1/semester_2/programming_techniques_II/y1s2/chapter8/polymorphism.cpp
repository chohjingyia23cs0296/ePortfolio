#include<iostream>
using namespace std;
#define PI 3.142
//Same action but different behaviour
class Shape{

};
class Circle:public Shape{
    private:
    double r;
    public:
    double getArea(){
        return PI*r*r;//Same action but different behaviour
    }
};
class Rectangle:public Shape{
    private:
    double width;
    double length;
    public:
    double getArea(){
        return width*length;//Same action but different behaviour
    }
};
