#include <iostream>
using namespace std;
void function();
int main(){
function();
cout << "Bye from main.\n";
system ("pause");
return 0;
}
void function(){
cout << "Bye! from function before exit\n";
exit(0);
cout << "Bye! from function before exit\n";
}