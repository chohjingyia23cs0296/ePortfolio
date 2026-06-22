#include<iostream>
using namespace std;


int main(){
    string str = "Hello World";
    string str2 = "Hello";
str2.append(" World");
cout << str2<<"\n"; // Output: Hello World

string sub = str.substr(6, 5); // Extract substring starting from index 6 with length 5
cout << sub; // Output: World



    return 0;
} 
