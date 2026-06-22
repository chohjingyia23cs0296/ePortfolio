#include <iostream>
using namespace std;
int function();
int main(){
function();
cout << "Bye from main.\n";
system ("pause"); 
return 0;
}
int function(){
cout << "Bye! from function before return\n";
return 0;
cout << "Bye! from function before return\n";
}