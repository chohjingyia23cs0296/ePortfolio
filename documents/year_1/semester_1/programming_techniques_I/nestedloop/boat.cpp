#include <iostream>
using namespace std;

int main(){
    int num=30;
    for(int a=1;a<=9;a++){
        for(int b=1;b<=30;b++){
            cout<<" ";
        }
        for(int c=1;c<=a;c++){
            cout<<"* ";
        }cout<<"\n";
       }
    for(int d=1;d<=6;d++){
        for(int e=1;e<=30;e++){
            cout<<" ";
        }cout<<"*"<<endl;       
    }
    for (int f = 1; f <= 4; f++) {
        for (int g = 1; g <= 2*f-1; g++) {
            cout <<" ";
        } 
        for (int h = 1; h<=35-2*f; h++) {
            cout << "* ";
        } 
        
            cout << "\n";
        }

        for(int i=1;i<=2;i++){
            for(int j=1;j<=i+3;j++){
                cout<<"- ";           
            }
            for(int m=1;m<=28-2*i;m++){
                cout<<"* ";
            } 
            for(int n=3;n<=6+i;n++){
                cout<<"- ";
            }
            cout<<endl;
        }
        for(int q=1;q<=2;q++){
            for(int p=1;p<=35;p++){
                    cout<<"- ";
                }cout<<endl;
        }
        
        
    
    
        
    return 0;
}


