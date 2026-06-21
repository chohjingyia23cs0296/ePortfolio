#include <iostream>
#include<cstring>
using namespace std;

int main(){
    char string1[16]="have a";
    char string2[9]="nice day";
    strcat(string1,string2);
    cout<<string1<<endl;
    cout<<string2<<endl;
    
    return 0;
}