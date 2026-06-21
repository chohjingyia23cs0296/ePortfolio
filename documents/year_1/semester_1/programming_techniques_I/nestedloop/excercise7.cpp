#include<iostream>
using namespace std;
int main(){
    int level;
    cout<<"Enter level: ";
    cin>>level;

    for(int i=1;i<=level;i++){
        for(int j=1;j<=level-i;j++){
            cout<<" ";
        }for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }
        cout<<"\n";
    }

    for (int i = level - 2; i >= 0; i--) {
        for (int j = 0; j < level-i-1; j++) {
            cout <<"/";
        }
    for(int k=0;k<2*i+1;k++){
        cout<<"*";
    }cout<<"\n";
    }
    
    return 0;
}