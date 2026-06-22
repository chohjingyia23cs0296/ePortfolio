#include <iostream>
#include <string>

using namespace std;

class Circle {

    private:int radius;
    double pi;
    string name;

    public:
    Circle(){
        radius=0;
        pi=3.142;
        name="Default Circle";
    }
    Circle(int r){
        radius=r;
        pi=3.14;
        name="Circle with radius"+to_string(r)+" ,Radius: "+to_string(pi);
    }
    Circle (int r,double p){
        radius=r;
        pi=p;
        name="Circle with radius "+to_string(r)+" ,radius: "+to_string(pi);
    }
    Circle(int r,double p,string n){
        radius=r;
        pi=p;
        name=n;
    }
    void print(){
    cout<<"Name: "<<name<<" ,radius: "<<radius<<",Pi: "<<pi<<endl;
}

};
int main(){

    Circle circle1;
    Circle circle2(5);
    Circle circle3(7,3.142);
    Circle circle4(7,3.14590,"Custom Circle");

    circle1.print();
    circle2.print();
    circle3.print();
    circle4.print();





    return 0;
}
/*
| Circle |
|--------|
| - radius: int |
| - pi: double |
| - name: string |
|--------|
| + Circle() |
| + Circle(r:int) |
| + Circle(r:int, p:double) |
| + Circle(n:string&) |
| + display(): void |
*/