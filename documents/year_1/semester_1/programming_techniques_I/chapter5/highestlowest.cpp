#include <iostream>
using namespace std;

int main() {
    const int SIZE=10;
    int num[SIZE];
    int highest,lowest;
    
    for(int i=0;i<SIZE;i++){
        cout<<"Num"<<i+1<<": ";
        cin>>num[i];
        highest = num[0];
        lowest = num[0];
    }

    for(int i=0;i<SIZE;i++){
        if(num[i]>highest){
            highest=num[i];
        }
    }cout<<"Highest: "<<highest<<endl;

    for(int i=1;i<SIZE;i++){
        if(num[i]<lowest){
            lowest=num[i];
        }
    }
    cout<<"Lowest: "<<lowest<<endl;
    
    return 0;
}