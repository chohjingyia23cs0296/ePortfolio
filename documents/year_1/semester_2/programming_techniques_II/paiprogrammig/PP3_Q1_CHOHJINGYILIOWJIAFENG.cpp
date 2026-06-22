#include<iostream>
#include<string>
using namespace std;

void phoneFormat(string phone){
    phone.insert(0,"+");
    phone.insert(4,"-");
    phone.insert(9,"-");
    cout<<"Your formatted handphone no. -> "<<phone<<endl;
    
}
int main(){
    string phone;
    cout<<"Enter your handphone no. ->";
    cin>>phone;
    phoneFormat( phone);
    return 0;
}