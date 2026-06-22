#include <iostream>
using namespace std;
#define PI 3.14159
class ThreeDimensionalObject{
    protected:
    double volume;
    public:
    ThreeDimensionalObject(){};
    virtual double getVolume(){
        return volume;
    }
    virtual void print(){
        cout<<"Volume: "<<getVolume()<<endl;
    }

};
class Sphere:public ThreeDimensionalObject{
    private:
    double radius;
    public:
    Sphere(double r):radius(r){};
    double getVolume()override{
        return (4.0/3.0)*PI*radius*radius*radius;
    }
    void print()override{
        cout<<"\nSphere's radius => "<<radius<<endl;
        ThreeDimensionalObject::print();
    }
}; 
class Cuboid:public ThreeDimensionalObject{
    private:
    double width;
    double length;
    double height;
    
    public:
    Cuboid(double w,double l,double h):width(w),length(l),height(h){};

    double getVolume()override{
        return width*length*height;
    }
    void print()override{
        cout<<"\nCuboid dimensions: "<<width<<" x "<<length<<" x "<<height<<endl;
        ThreeDimensionalObject::print();
    }
};
int main(){
    int choice;
    double width,length,height;
    double radius;
    cout<<"Enter the type of object 1: Cuboid, 2:Sphere => ";
    cin>>choice;
    if(choice==1){
        cout<<"Enter the cubodi's dimensions,width,length and height => ";
        cin>>width>>length>>height;
        Cuboid cuboid(width,length,height);
        cuboid.print();
    }else if(choice==2){
        cout<<"Enter the radius => ";
        cin>>radius;
        Sphere sphere(radius);
        sphere.print();
    }else{
        cout<<"Invalid input.\n";
    }
    return 0;
}