#include <iostream>
using namespace std;

int main(){
    int age;
    cout<<"Please enter your age: ";
    cin>>age;
    
        if(age>0&&age<17){
            cout<<"Not allowed"<<endl;
            
        }else if(age>18&&age<65){
            cout<<"Allowed without helper."<<endl;
    }else{
            cout<<"allowed a helper."<<endl;
    }
    
    return 0;
}    
