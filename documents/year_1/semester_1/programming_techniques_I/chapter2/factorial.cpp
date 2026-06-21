#include <iostream>
using namespace std;
int main() {
    int num,factorial=0;
    cout<<"Enter the factorial number: ";
    cin>>factorial;
    int sum=1 ;

    for(int count=factorial;count>=1;count--){

        cout<<count;
        
        if(count>1){
            cout<<" * ";}
        else{cout<<" = ";}
        sum*=count; 
    }
    cout<<sum<<endl;

    if(sum%5==0){
        cout<<"This is factorial for 5. "<<"\n";
    }else{
        cout<<"This is not factorial for 5. "<<"\n";
    }


    return 0;
}
