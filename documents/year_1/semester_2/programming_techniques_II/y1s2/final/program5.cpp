#include<iostream>
#include<vector>
using namespace std;

class Polygon{
    public:
    virtual void display(){
        cout<<"Generic Polygon:\n";
    }
    virtual int calcArea(){
        return 0;
    }
};

class Rectangle:public Polygon{
    private:
    int width;
    int length;
    public:
    Rectangle(int w,int l):width(w),length(l){};
    int calcArea()override{
        return width*length;
    }
    void display()override{
        cout<<"Rectangle: \n";
        cout<<"\tWidth = "<<width<<"Length = "<<width<<endl;
    }
};

class Triangle:public Polygon{
    private:
    int base;
    int height;
    public:
    Triangle(int b,int h):base(b),height(h){};
    int calcArea()override{
        return 0.5*base*height;
    }
    void display()override{
        cout<<"Triangle :\n";
        cout<<"\tBase = "<<base<<"Height = "<<height<<endl;
    }

};
int main(){
    vector <Polygon*>polygon;
    polygon.push_back(new Triangle(10, 20));
    polygon.push_back(new Rectangle(20, 20));
    polygon.push_back(new Polygon());
    polygon.push_back(new Rectangle(15, 10));

    int total=0;
    for(int i=0;i<4;i++){
        cout<<"Polygon #"<<i+1<<endl;
        polygon[i]->display();
        int area=polygon[i]->calcArea();
        cout<<"\tArea = "<< area<<endl;
        total+=polygon[i]->calcArea();
    }
    cout<<"The total area of all polygon = "<<total<<endl;
}
