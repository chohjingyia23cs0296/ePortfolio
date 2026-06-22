#include<iostream>
using namespace std;
int main(){

    const int CAR_TYPES = 5;
const int COLOR_TYPES = 6;
int total;
double sales[CAR_TYPES][COLOR_TYPES] = {
        {1000.0, 1200.0, 800.0, 1500.0, 900.0, 1100.0},
        {900.0, 1100.0, 700.0, 1300.0, 800.0, 1000.0},
        {1200.0, 1400.0, 1000.0, 1700.0, 1100.0, 1300.0},
        {800.0, 1000.0, 600.0, 1200.0, 700.0, 900.0},
        {1100.0, 1300.0, 900.0, 1600.0, 1000.0, 1200.0}
    };
    for(int i=0;i<CAR_TYPES;i++){
        total=0;
        for(int j=0;j<COLOR_TYPES;j++){
            total+=sales[i][j];
            cout<<"Sales for"<<i+1<<"car type is"<<total<<endl;
        }
        
    }

    return 0;
}
