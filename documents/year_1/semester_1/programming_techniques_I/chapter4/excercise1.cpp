#include <iostream>
#include<cctype>
using namespace std;
int main(){
    char ch='&';

    if(isdigit(ch)){
        cout<<"digit";
    }else if(isalpha(ch)){
        cout<<"letter";
    }else{
        cout<<"Special character";
    }
}