#include <iostream>
using namespace std;

int main(){
    int row;
    cout<<"Enter the number of row: ";
    cin>>row;

    for(int count=1;count<=row;count++){
        for(int num=1;num<=count;num++){
            cout<<count;
        }cout<<"\n";
    }

    return 0;
}