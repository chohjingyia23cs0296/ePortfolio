#include <iostream>
#include<iomanip>
using namespace std;

int main(){
    const int NUM_DIVS=3;
    const int NUM_QTRS=4;
    double sales[NUM_DIVS][NUM_QTRS];
    double totalSales=0;
    int div,qtr;
    cout<<"This is the total sales of \n";
    cout<<"all the company division.\n";
    cout<<"Enter the following sales information: \n\n";

    for(div=0;div<NUM_DIVS;div++){
        for(qtr=0;qtr<NUM_QTRS;qtr++){
        cout<<"Divison"<<(div+1);
        cout<<",Quater"<<(qtr+1)<<": $";
        cin>>sales[div][qtr];
    }cout<<endl;
    
}
    
    for(div=0;div<NUM_DIVS;div++){
        for(qtr=0;qtr<NUM_QTRS;qtr++){
        totalSales+=sales[div][qtr];
    }
    cout<<fixed<<setprecision<<showpoint<<setprecision(2);
    cout<<"Total :"<<totalSales<<endl;
}
    return 0;
}
