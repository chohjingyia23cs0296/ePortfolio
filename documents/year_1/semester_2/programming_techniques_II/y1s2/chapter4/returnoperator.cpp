#include<iostream>
#include<cmath>
using namespace std;

class Point2d{
    private: 
    int x;int y;
    public:
    double operator-(const Point2d&right){
        return sqrt(pow((x - right.x),2)+pow((y - right.y),2));
    }
public:
    // Constructor
    Point2d(int _x, int _y) : x(_x), y(_y) {}

};
int main(){
    Point2d point1(2,2), point2(4,4);
    cout<<point2-point1<<endl;
}