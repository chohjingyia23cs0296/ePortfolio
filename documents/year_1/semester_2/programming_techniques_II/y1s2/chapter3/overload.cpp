#include<iostream>
using namespace std;

class Rectangle{
    private:int height;
    int width;
    public:
    Rectangle(int);
    Rectangle(int,int);
    int getSide(){
        return height;
    }
    int getArea(int);
    int getArea(int,int);
 
};

Rectangle::Rectangle(int x){
        height=x;
        width=x;
    }
    Rectangle::Rectangle(int x,int y){
        height=x;
        width=y;
    }
    int Rectangle::getArea(int x){
        return x*x;
    }
    int Rectangle::getArea(int x,int y){
        return x*y;
    }
int main(){
    
    Rectangle c(5,6);//30
    Rectangle d(6);//36
    cout<<d.getArea(d.getSide())<<endl;//36
    cout<<c.getArea(5,6);//30
    return 0;
}