#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2 = "Hello";

    // Using the assignment operator
    str1 = "World";
    string str3=str1+str2;
    cout << "String assigned using assignment operator: " << str3 << endl;

    // Using the assign() method
    str1.assign("C++");
    cout << "String assigned using assign() method: " << str1 << endl;

    return 0;
}
