#include<iostream>
using namespace std;
int main(){
    const int size=5;
    int num[size];
    for(int i=0;i<size;i++){
        cout<<"Num "<<(i+1)<<":";
        cin>>num[i];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(num[j]<num[j+1]){
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<num[i]<<" ";
    }
    

    return 0;
}