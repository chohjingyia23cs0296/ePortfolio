#include<iostream>
#include<iomanip>
using namespace std;
class ThreeDimensionObject{
    protected:
    double volume;
    public:
    ThreeDimensionObject(){};
    virtual double getVolume(){
        return volume;
    };
    virtual void print(){
        cout<<"Volume: "<<getVolume()<<endl;
    }
};
class Cuboid:public ThreeDimensionObject{
    private:
    int height;
    int length;
    int width;
    public:
    Cuboid(int w,int l,int h):width(w),length(l),height(h){};
    double getVolume()override{
        return height*length*width;
    }
    void print()override{
        cout<<"\nCuboid dimension: "<<width<<" x "<<length<<" x "<<height<<endl;
        ThreeDimensionObject::print();
        
    }

};
class Sphere:public ThreeDimensionObject{
    private:
    double radius;
    public:
    Sphere(double r):radius(r){};
    double getVolume()override{
        return (4.0/3.0)*3.1412*radius*radius*radius;
    }
    void print()override{
        cout<<"\nSphere radius:"<<radius<<endl;
        ThreeDimensionObject::print();
    }
};

int main() {
    int choice = 0;
    int l, h, w;
    double radius;
    
    cout << "Enter the type of object: 1: Cuboid, 2: Sphere => ";
    cin >> choice;
    
    if(choice==1){
        cout << "Enter the cuboid dimensions (width, length, height): ";
            cin >> w >> l >> h;
            Cuboid cuboid(w, l, h);
            cuboid.print();
    }else if(choice==2){
        cout << "Enter the sphere radius: ";
            cin >> radius;
            Sphere sphere(radius);
            sphere.print();
    }else{
        cout << "\nInvalid input";
    }

    return 0;
}


