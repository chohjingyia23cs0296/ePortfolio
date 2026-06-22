#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:

    Circle(double r) {
        radius = r;
    }
    double getRadius()const{
        return radius;
    }

    double getArea()const {
        return radius * radius * 3.14;
    }
    
};

void printCircle(Circle a){
    cout<<a.getRadius()<<" "<<a.getArea();
}
int main(){
    Circle ab(5.5);
    printCircle(ab);
    return 0;
}
