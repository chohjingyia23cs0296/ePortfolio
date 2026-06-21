#include <iostream>
using namespace std;

int main(){
    int month[12];
    double total,rainfall,highest,lowest,sum,avg;
    

    for(int i=0;i<12;i++){
        cout<<"Rainfall on month"<<i+1<<":";
        cin>>month[i];
        while(month[i]<0){
            cout<<"Rainfall cannot be negative.Enter again: ";
            cin>>month[i];
        }
        highest=month[0];
        lowest=month[0];
        sum+=month[i];
    }
    
    avg=sum/12;
    for(int i=0;i<12;i++){
        if(month[i]>highest){
            highest=month[i];
        }
    }cout<<"Highest rainfall: "<<highest<<endl;
    
    for(int i=0;i<12;i++){
        if(month[i]<lowest){
            lowest=month[i];
        }
    }cout<<"Lowest rainfall: "<<lowest<<endl;
    cout<<"Total rainfall of the year: "<<sum<<endl;
    cout<<"Aaverage rainfall: "<<avg;
    return 0;
}