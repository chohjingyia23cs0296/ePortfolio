#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class SpeedDistanceTime{
    private:
    double startHours;
    double startMinutes;
    double endHours;
    double endMinutes;
    double timeTaken;
    double distance;
    double speed;

    double calcTimeTaken(){
        double hours=endHours-startHours;
        double minutes=endMinutes-startMinutes;
        double minutescalc=minutes/60;
        timeTaken=hours+minutescalc;
    }
    double calcDistance(){

        distance=speed*timeTaken;
        return distance;
    }

    public:
    SpeedDistanceTime(double t=0,double d=0){
        timeTaken=t;
        distance=d;
    }
    double operator+(const SpeedDistanceTime&obj){
        return distance+obj.distance;
    }
    friend ostream& operator<<(ostream& os, const SpeedDistanceTime& sdt);
    friend void readInput( SpeedDistanceTime &sdt);
};
 void readInput( SpeedDistanceTime&sdt){
    cout<<"Enter start time and end time using 24-hour time format (hh:mm) \n";
    cout<<"\t\tStart time = ";
    cin>>sdt.startHours;
    cin.ignore();
    cin>>sdt.startMinutes;
    cin.ignore();
    cout<<"\t\tEnd time = ";
    cin>>sdt.endHours;
    cin.ignore();
    cin>>sdt.endMinutes;
    cin.ignore();
    cout<<"\nEnter speed in km/h = ";
    cin>>sdt.speed;
    
    sdt.calcTimeTaken();
    sdt.calcDistance();
}
ostream& operator<<(ostream&os,const SpeedDistanceTime&obj){
        os<<fixed<<setprecision(2);
        os<<"Time taken = "<< obj.timeTaken<<"hours(s)\n";
        os<<"Speed = "<< obj.speed<<"km/h\n";
        os<<"Distance = "<< obj.distance<<"km\n";
} 
int main(){
    SpeedDistanceTime obj1,obj2;
    cout<<"Input for Object 1\n";
    readInput(obj1);
    cout<<"Input for Object 2\n";
    readInput(obj2);
    cout<<"\n**OUTPUT**\n";
    cout<<"Object 1:\n";
    cout<<obj1<<endl;
    cout<<"Object 2:\n";
    cout<<obj2<<endl;

    cout << "Total distance for Object 1 and 2 = " << obj1+obj2 << " km" << endl;
}