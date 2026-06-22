#include<iostream>
using namespace std;
class Rectangle{
    private:
    double width;
    double length;

    public:
    void setWidth(double);
    void setLength(double);
    double getWidth()const;
    double getLength()const;
    double getArea()const;

    

};
void Rectangle::setWidth(double w){
    width=w;
}
void Rectangle::setLength(double l){
    length=l;
}
double Rectangle::getWidth()const{
    return width;
}
double Rectangle::getLength()const{
    return length;
}
double Rectangle::getArea()const{
    return width*length;
}
int main(){
    Rectangle box;
    double length,width;
    cout<<"Enter the length: ";
    cin>>length;
    cout<<"Enter the width: ";
    cin>>width;
    box.setLength(length);
    box.setWidth(width);
    cout<<"Area: "<<box.getArea();

}
