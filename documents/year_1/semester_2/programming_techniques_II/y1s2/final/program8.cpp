#include<iostream>
using namespace std;
class Polygon{
    public:
    Polygon(){};
    virtual int calcArea(){
        return 0;
    }
    virtual void display(){
        cout<<"Generic Polygon: \n ";
    }
};
class Rectangle:public Polygon{
    private:
    int width;
    int length;
    public:
    Rectangle(int w,int l){
        width=w;
        length=l;
    }
    int calcArea()override{
        return width*length;
    }
    void display()override{
        cout<<"Rectangle\n";
        cout<<"\tWidth = "<<width<<", Length = "<<length<<endl;
    }
};
class Triangle:public Polygon{
    private:
    int base;
    int height;
    public:
    Triangle(int b,int h):base(b),height(h){};
    int calcArea()override{
        return (1.0/2.0)*base*height;
    }
    void display()override{
        cout<<"Triangle\n";
        cout<<"\tBase = "<<base<<", Height = "<<height<<endl;
    }
};
int main(){
    Triangle t(10,20);
    Rectangle r(20,20);
    Polygon p;
    Rectangle r1(15,10);
    int total=0;
    Polygon *polygon[4]={&t,&r,&p,&r1};
    for(int i=0;i<4;i++){
        cout<<"Polygon #"<<i+1<<endl;
        polygon[i]->display();
        cout<<"\tArea = "<<polygon[i]->calcArea()<<"\n\n";
        total+=polygon[i]->calcArea();

    }
    cout<<"\nThe total area of all polygons = "<<total<<endl;
}