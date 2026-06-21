#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

     double val= 10.345;
     cout<< setprecision(5) << val<< endl; //(a)10.345
     cout<< setprecision(4) << val<< endl; //(b)10.35
     cout<< setprecision(3) << val<< endl; //(c)10.3
     cout<< setprecision(2) << val<< endl; //(d)10
     cout<< setprecision(1) << val<< endl;//(e)1e+001
     cout<< "ApaKhabar\n Semua\n" << endl; //(f)ApaKhabar
                                           // Semua 
     cout<< static_cast<int>(val)/2 << endl; //(g)5
     cout<< setw(6) << val*5 << endl; //(h)5e+001
     cout<< showpoint <<fixed<<setw(8) << val<< endl;//(i)    10.3
     return 0;
}


     
     