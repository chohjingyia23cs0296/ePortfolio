#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number for the multiplication table(between 1 and 10): ";
    cin>>num;

    for(int i=0;i<10;i++){
        cout<<num<<"x"<<i<<"="<<(num*i)<<endl;

    }

    return 0;
}
