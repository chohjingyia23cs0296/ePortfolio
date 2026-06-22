#include<iostream>
#include<cmath>
using namespace std;
auto powerOf(float exponent){
    return [exponent](float number){return pow(number,exponent);};

}

int main(){
    auto square=powerOf(2);
    auto cube=powerOf(3);
    auto squareRoot=powerOf(0.5);

    cout<<"Square: "<<square(25)<<endl;
    cout<<"Cube: "<<cube(2)<<endl;
    cout<<"Square Root: "<<squareRoot(2)<<endl;
    
}