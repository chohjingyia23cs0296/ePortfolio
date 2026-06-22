#include <iostream>
#include<cstring>
using namespace std;

class login_exception {

};

int main() {
    char uname[10], password[10];
    login_exception invalid_login;

    cout << "\n Enter username: ";
    cin >> uname;
    cout << "\n Enter password: ";
    cin >> password;

    try {
        if (strcmp(uname, "abc") == 0 && strcmp(password, "abc") == 0) {
            cout<<"\n Salam... \n";
        }else{
            throw invalid_login;
        }
    } catch (login_exception e) {
        cout << "\nInvalid username or password\n";
    }
    /*The username and password both match the expected "abc". 
    Therefore, the condition strcmp(uname, "abc") == 0 && strcmp(password, "abc") == 0 
    evaluates to true, and the program prints "Salam...". No exception is thrown, 
    so the catch block is not executed.*/
    
    /*The username is "abc", but the password is "abb", which does not match "abc". 
    Therefore, the condition strcmp(uname, "abc") == 0 && strcmp(password, "abc") == 0 
    evaluates to false, and an exception of type login_exception is thrown. 
    The catch block catches this exception and prints "Invalid username or password".
    */
    return 0;
}
