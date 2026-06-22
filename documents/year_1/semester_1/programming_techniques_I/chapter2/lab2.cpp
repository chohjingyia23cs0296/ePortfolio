#include <iostream>
using namespace std;

int main() {
    int integer;
    int remainder;
    int sum=0;

    cout<<"Ener the integer number: ";
    cin>>integer;
    
    while(integer>0){
        remainder=integer%10;
        cout<<remainder;
        integer/=10;
      
        if(integer>0){
            cout<<" + ";
        }else{
            cout<<" = ";
        }
        sum+=remainder;
  
    }     
    cout<<sum<<endl;

    if(sum%3==1){
        cout<<sum<<" is not a multiple of 3"<<endl;
        cout<<"Its remainder is 1"<<endl;
    }else if(remainder%3==2){
        cout<<sum<<" is not a multiple of 3"<<endl;
        cout<<"Its remainder is 2"<<endl;
    }else{
        cout<<sum<<" is  a multiple of 3"<<endl;
    }

    return 0;
}

