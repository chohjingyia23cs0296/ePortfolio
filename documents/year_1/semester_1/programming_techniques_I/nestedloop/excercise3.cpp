#include <iostream>
using namespace std;

int main(){
    int level;
    cout<<"Enter number of level: ";
    cin>>level;

    for(int i=1;i<=level;i++){
        for(int j=1;j<=level-i;j++){
            cout<<"/";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}