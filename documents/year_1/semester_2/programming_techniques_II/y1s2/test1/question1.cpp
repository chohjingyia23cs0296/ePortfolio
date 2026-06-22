// Program 1
#include<iostream>
using namespace std;
const double PI=3.142;
class Cone{
    private:
    double radius;
    double height;
    public:
    inline void readData() {
        cout<<"Radius: ";
        cin>>radius;
        cout<<"Height:";
        cin>>height;
    }
    inline double calc_baseArea()const{
        double baseArea =PI*radius*radius;
        return baseArea;
    }
    inline double calc_volume()const{
        double volume=(1.0/3)*PI*radius*radius*height;
        return volume;
    }
    inline void displaydata(){
        cout << "Base Area: " << calc_baseArea() << endl;
        cout << "Volume: " << calc_volume() <<endl;
    }
};
int main(){
    Cone cnl;
    cnl.readData();
    cnl.calc_baseArea();
    cnl.calc_volume();
    cnl.displaydata();
    return 0;
}
