#include <iostream>
using namespace std;

int main(){
    const int CAR_TYPES = 5;
    const int COLOR_TYPES = 6;
    int total;

    double sales[CAR_TYPES][COLOR_TYPES] = {{188, 297, 379, 486, 594, 666}, 
    {686, 591, 478, 379, 284, 111}, 
    {382, 573, 777, 982, 189, 555},
    {188, 297, 379, 486, 594, 666}, 
    {188, 297, 379, 486, 594, 666}};

    
    for(int i=0;i<COLOR_TYPES;i++){
        total=0;
        for(int j=0;j<CAR_TYPES;j++){
            total+=sales[j][i];
        }cout<<"Total sales for COLOR TYPES"<<(i+1)<<": "<<total<<endl;
    }
    
    
    return 0;
}