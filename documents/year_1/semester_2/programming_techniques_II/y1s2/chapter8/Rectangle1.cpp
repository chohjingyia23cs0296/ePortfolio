#include<iostream>
using namespace std;

class Shape{
    public:
    Shape(){};
    virtual double  getArea(){
        return 0;
    }
    

};
class Circle:public Shape{
    private:
    double radius;
    public:
    Circle(double r){
        radius=r;
    }
    double getArea(){
        return 3.142*radius*radius;
    }

};
class Rectangle:public Shape{
    private:
    double length;
    double width;
    public:
    Rectangle(double l,double w){
        width=w;
        length=l;
    }
    double getArea(){
        return length*width;
    }
    
};
int main(){
    Circle s1(3.0);
    Rectangle s2(4.0,3.0);

    
    Shape*list[2]={&s1,&s2};
    for(int i=0;i<2;i++){
        cout<<"Area"<<list[i]->getArea()<<endl;
    }
    
    
}