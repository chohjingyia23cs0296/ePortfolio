#include <iostream>
using namespace std;


int main() { 
    int size=10;  
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size-i+4;j++){
            cout<<" ";
        }
        for(int k=1;k<=2*i-1;k++){
        cout<<"*";
    }cout<<"\n";
    }
    
    for(int i=1;i<=size*2;i++){
        for(int r=1;r<=4;r++){
            cout<<" ";
        }
        for(int r=1;r<=19;r++){
            cout<<"*";
        }
        cout<<"\n";
    }  

    for(int m=1;m<=size;m++){
        for(int n=-2;n<=size-m;n++){
            cout<<"*";
        } 
        for(int q=1;q<=m;q++){
            cout<<" ";
        }
        for(int q=1;q<=m;q++){
            cout<<" ";
        }
        for(int n=-2;n<=size-m;n++){
            cout<<"*";
        } 
        cout<<"\n";
    }
    
    
    
    return 0;
}
