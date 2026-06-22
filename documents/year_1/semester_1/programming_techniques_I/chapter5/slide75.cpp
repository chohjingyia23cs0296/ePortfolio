#include<iostream>
using namespace std;

int main(){
    const int num_month=12;
    const int string_size=10;
    char months[num_month][string_size]={"January","February","March","April","May","June",
    "July","August","September","October","November","December"}; 
    int days[num_month]={31,28,31,30,31,30,31,31,30,31,30,31};

    for(int i=0;i<num_month;i++){
            cout<<months[i]<<" has "<<days[i]<<"."<<endl;
       
    }
    return 0;
}