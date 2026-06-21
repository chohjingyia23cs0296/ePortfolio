#include <iostream>
using namespace std;

int main() {
    char phonenumber[20],name[30],address[100],major[50];
 

    cout << "Enter your name: ";
    cin.getline(name,30);
    cout << "Enter your address (with city, state, and ZIP code): ";
    cin.getline(address,100);
    cout << "Enter your phone number: ";
    cin.getline(phonenumber,20);
    cout << "Enter your university major: ";
    cin.getline(major,50);

    cout<<"Personal detail\n";
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone number: "<<phonenumber<<endl;
    cout<<"Major: "<<major<<endl;

    return 0;
}
