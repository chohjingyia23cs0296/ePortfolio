#include <iostream>
using namespace std;

int main(){
    const int SIZE=15;
    char input[SIZE];
    
    cout<<"Enter a name ";
    cin.getline(input,SIZE);
    for(int i=0;input[i] != '\0';i++)
    input[i]=toupper(input[i]);
    cout<<"The name in upper case is:" << input;

    return 0;
}