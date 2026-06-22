#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle{
    private:
    double length;
    double width;

    public:

    Rectangle(double len,double w); //Constructor
    void setWidth(double);
    void setLength(double);
    double getLength()const{
    return length;}
    double getWidth()const{
    return width;}
    double getArea()const{
    return length*width;}
};
#endif


