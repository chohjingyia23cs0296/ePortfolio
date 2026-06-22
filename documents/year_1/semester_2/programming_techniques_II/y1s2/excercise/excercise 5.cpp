/*
1a)i)#include <string>
ii)
iii)The length of the city is 13
bi)#include <string>
ii)
iii)Size of message1: 6

Size of message2: 6
iv) remian the same
v)No difference
*/

#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int main(){


    string message1="Happy";
    string message2="Birthday";
    cout<<message1<<endl;
    cout<<message2<<endl;
    cout<<"Size of message 1 :"<<message1.size()<<endl;
    cout<<"Size of message 2 :"<<message2.size()<<endl;
    message1=message1+message2;
    cout<<message1<<endl;

}
#include<iostream>
#include<string>
using namespace std;

void phoneFormat(string &object){
    object.insert(0,"+");
    object.insert(4,"-");
    object.insert(9,"-");

}

int main(){
    string phoneNumber;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;
    phoneFormat(phoneNumber);
    cout << "Your formatted phone number: " << phoneNumber << endl;

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, year, firstName, lastName, title, formatName;

    cout << "Enter author of the book -> ";
    getline(cin, name);

    size_t spacePos = name.find(' ');
    firstName = name.substr(spacePos + 1);
    lastName = name.substr(0, spacePos);

    formatName = lastName + ", " + firstName ;

    cout << "Enter year of publication: ";
    cin >> year;
    year=("("+year+")");
    cout << "Enter a book title: ";
    cin.ignore(); 
    getline(cin, title);
    title=title.insert(0," ");
    formatName += year + " " + title;

    cout << "The Formatted Book reference: " << endl;
    cout << formatName << endl;

    return 0;
}
