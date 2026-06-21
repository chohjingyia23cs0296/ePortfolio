#include<iostream>
using namespace std;
int main (){
    int size;
    cout<<"Enter the size of rocket: ";
    cin>>size;
    for(int a=1;a<=size;a++){
        for(int b=1;b<=size-a+4;b++){
            cout<<"/";
        }
        
        for(int d=1;d<=2*a-1;d++){
            cout<<"*";
        }
            cout<<"\n";
        
    }
     for (int g = 1; g <= size; g++) {
        for (int h = 1; h <= 4; h++) {
            cout << " ";
        }
        
        for (int e = 1; e <= size * 2-1; e++) {
            cout << "*";
        }
        cout << endl;
    }

    for(int h=1;h<=size;h++){
        for(int i=1;i<=size-h+3;i++){
            cout<<"*";
        }
        for(int j=1;j<=h;j++){
            cout<<" ";
        }
        for(int k=1;k<=h;k++){
            cout<<" ";
        }
        for(int m=1;m<=size-h+3;m++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;

}