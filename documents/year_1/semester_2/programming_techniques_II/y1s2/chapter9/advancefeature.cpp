#include<iostream>
using namespace std;

int totalDays(int days, int weeks)
{
if ((days < 0) || (days > 7))
throw "Invalid number of days!";
//the argument to throw is a literal c-string
else
return (7 * weeks + days);
}

int main(){
int totDays,days, weeks;
cout << "Enter no. of. days and no. of. weeks =>";
cin >> days >> weeks;
try{
totDays = totalDays(days, weeks);
cout << "Total days: " << totDays;
}
catch (const char *msg){
cout << "Error: " << msg;
}
return 0;
}
//code in the try-block is called protected code
//code in the catch-block is called exception handler

