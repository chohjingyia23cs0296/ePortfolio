#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "Hello, ";
    string str2 = "World!";
    string str5;

    string str3 = str1; // Assigning str1 to str3
       string str4=str1.append(str2); // Concatenating str1 and str2 into str5
       str5.assign(str2);

    cout << "Concatenated string: " << str3<< endl; // Output: "Hello, World!"
    cout << "Assigned string from str1: " << str4 << endl; // Output: "Hello, "
    cout << "Assigned string from str1: " << str5 << endl;


    return 0;
}
