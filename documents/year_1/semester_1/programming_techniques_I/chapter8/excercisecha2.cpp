#include <iostream>
#include <cmath> // For the pow function
#include <iomanip>
using namespace std;

// Constant for pi.
const double PI = 3.14159;
const int SIZE=5;

//Structure declaration
struct Circle
{
double diameter;
double radius; // A circle's radius
double area; // A circle's diameter
// A circle's area (Complete the statement)
};//1

int main(){
    double diameter[SIZE];//4
       Circle c[SIZE]={{2,1,0},{3,1.5,0},{4,2,0},{5,2.5,0},{6,3,0}}; // Define a structure variable
       // Get the circle's diameter.
       for(int i=0;i<SIZE;i++){
        c[i].radius=c[i].diameter/2;
         c[i].area = PI * pow(c[i].radius, 2.0);//5
       }
       
       // Display the circle data.
       cout << fixed << showpoint << setprecision(2);
       cout << "The radius and area of the circle are:\n";
       for(int i=0;i<SIZE;i++){
        cout << "Radius"<<i+1<<": " << c[i].radius << endl;
       cout << "Area "<<i+1<<" :" << c[i].area<< endl;

       }
       

       return 0;
}//2