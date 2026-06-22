#include<iostream>
using namespace std;

class Rectangle{
    private:
    double length;
    double width;

    public:
    Rectangle(double len,double w){
    length=len;
    width=w;
    }
    ~Rectangle(){

    }
    void setLength(double len){
        length=len;
    }
    void setWidth(double w){
        width=w;
    }
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
    double getArea(){
        return width*length;
    }


};
int main(){

 
    Rectangle *rectPtr;
    rectPtr=new Rectangle(10,15);
    rectPtr->setLength(10.0);
    rectPtr->setWidth(15.0);
    
    cout << "Area of the rectangle: " << rectPtr->getArea() <<endl;
    delete rectPtr;
    rectPtr=0;

    return 0;

}
    