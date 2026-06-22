#include<iostream>
using namespace std;

int main(){
    char input;
    
    do{
        cout<<"Do you want to repeat the program or quit? (R/Q): ";
        cin>>input;
        input=toupper(input);

        if( input=='R'||input=='Q'){
            cout<<"Quit the program. ";
            break;
        }else{
            cout<<"Invalid input."<<endl;
        }
        
    }while(true);
   
    return 0;
}
/*
    1.isalpha:  checks whether a character is an alphabet (a to z and A-Z) or not.

2.isalnum:check whether a alphanumeric character(0-9),(A-Z),(a-z)

3.isdigit:check whether a character is numeric character or not(0-9)

4.islower: checks whether a character is lowercase alphabet (a-z) or not.

5.isupper:checks whether a character is uppercase alphabet (A-Z) or not.

6.isprint:checks whether a character is printable character or not

7.ispunct:checks whether a character is a punctuation or not.

8.isspace:checks if ch is a whitespace character as classified by the current C locale. By default, the the following characters are whitespace characters.

9.toupper:converts the lowercase letter c to the corresponding uppercase letter

10.tolower:convert the uppercase letter C to the corresponding lower letter

2.little=tolower(big)

3.65

4.
*/