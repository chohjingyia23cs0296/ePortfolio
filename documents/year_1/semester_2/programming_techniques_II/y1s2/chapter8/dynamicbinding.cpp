#include<iostream>
using namespace std;
#define PI 3.142
class Shape{
    public:
    Shape(){};
    virtual int getArea()const{
        return 0;
    }
};
class Circle:public Shape{
    private:
    double r;
    public:
    Circle(int _r){
        r=_r;
    }
     int getArea()const{//override 
        return PI*r*r;
    }
    void printRadius()const{
        cout<<"Radius "<<r<<endl;
    }
};
class Rectangle:public Shape{
    private:
    double width;
    double length;
    public:
    Rectangle(double w,double l){
        width=w;
        length=l;
    }
    int getArea()const{//override
        return width*length;
    }
};
void displayArea(Shape*p){
    cout<<"Area= "<<p->getArea()<<endl;
}
int main(){
    Shape*p;
    Shape s;
    Circle c(10);
    Rectangle r(2,6);
    
    //dyanmic binding
    //displayArea(&s);
    //displayArea(&c);
    //displayArea(&r);
    /*
    Shape*list[3]={&s,&c,&r};
    for(int i=0;i<3;i++){
        cout<<"Area= "<<list[i]->getArea()<<endl;
    }
    
    */
    //p->printRadius(); error,Shape does not have printRadius,it belong to Circle

    //static binding
    p=&s;
    cout<<"Shape area: "<<p->getArea()<<endl;
    p=&c;
    cout<<"Circle area: "<<p->getArea()<<endl;
    p=&r;
    cout<<"Rectangle area: "<<p->getArea()<<endl;

    return 0;


}