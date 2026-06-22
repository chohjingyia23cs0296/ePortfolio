#include <iostream>
#include <string>

using namespace std;

int main() {
    // Convert string to double
    string str = "3.14";
    double d = stod(str);
    cout << "String converted to double: " << d << endl;

    // Append strings
    string str1 = "Hello";
    string str2 = "World";
    str1.append(" ");
    str1.append(str2);
    cout << "Appended string: " << str1 << endl;

    // Substring
    string fullString = "This is a long sentence.";
    string substring = fullString.substr(5, 2); // Start from index 5, take 2 characters
    cout << "Substring: " << substring << endl;

    // Replace substring
    string originalString = "I like apples";
    string replacedString = originalString;
    replacedString.replace(7, 6, "oranges"); // Replace "apples" starting from index 7 with "oranges"
    cout << "Replaced string: " << replacedString << endl;

    // Convert double to string
    double number = 6.28;
    string str3 = to_string(number);
    cout << "Double converted to string: " << str3 << endl;

    return 0;
}
