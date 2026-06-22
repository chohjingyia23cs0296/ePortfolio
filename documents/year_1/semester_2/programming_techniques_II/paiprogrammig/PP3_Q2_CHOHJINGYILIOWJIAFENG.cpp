#include<iostream>
#include<string>
using namespace std;

int main(){
    string string1="Programming is a subject!";
    cout<<string1<<endl;

     string1.insert(17,"good ");
     cout<<string1<<endl;

    string1.replace(12,string1.length(),"reject!");

    cout<<string1<<endl;


    return 0;

}