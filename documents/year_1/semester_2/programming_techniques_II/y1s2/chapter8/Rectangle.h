#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
    private:
    double width;
    double length;
    public:
    class NegativeSize{};
    Rectangle(){
        width=0.0;
        length=0.0;
    }
    void setWidth(double w);
    void setLength(double l);
    double getWidth();
    double getLength();
    double getArea();
};

#endif