#include <iostream>
#include <string>
using namespace std;

void phoneFormat(string);

int main() {
    string num;
    cout << "Enter your phone number: ";
    cin >> num;
    phoneFormat(num);

    return 0;
}

void phoneFormat(string num) {
    string formattedNumber = "+";
    int count = 0;

    for (char c : num) {
        if (isdigit(c)) {
            formattedNumber += c;
            count++;
            if (count == 3 || count == 7) {
                formattedNumber += '-';
            }
        }
    }

    cout << "Your formatted phone number: " << formattedNumber << endl;
}
