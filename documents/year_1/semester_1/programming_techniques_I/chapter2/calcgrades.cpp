#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    int count1=0,count2=0,count3=0;
    char grades;

    while(grades!='e'){
        cout<<"Enter the letter grades[Enter 'e' character to end input]: "<<endl;
        cin>>grades;

    if (grades == 'e') {
            break;
        }

        switch(grades){
            case 'A':  
                        count1++;
                        
                        break;
            case 'B':   
                        count2++;
                        
                        break;

            case 'C' :  count3++;
                        
                        break;

            default: cout<<"Incorrect letter grade entered "<<endl;
                    
        }
    }
        cout<<"Total for each letter grade are: "<<endl;
        cout<<"A: "<<count1<<endl;
        cout<<"B: "<<count2<<endl;
        cout<<"C: "<<count3<<endl;
        cout<<"Press any key to continue..."<<endl;
        
    
    return 0;
}    
