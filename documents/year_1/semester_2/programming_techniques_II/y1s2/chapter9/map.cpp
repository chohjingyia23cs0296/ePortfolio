#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Convert a string to lowercase
string toLower(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

string dayNumToName(int d) {
    const string DAYS[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    if (d < 1 || d > 7) {
        return "Invalid day number";
    }
    return DAYS[d - 1];
}

int dayNameToNum(string n) {
    map<string, int> DAYS = {{"mon", 1}, {"tue", 2}, {"wed", 3}, {"thu", 4}, {"fri", 5}, {"sat", 6}, {"sun", 7}};
    n = toLower(n);
    if (DAYS.find(n) != DAYS.end()) {
        return DAYS[n];
    }
    return -1; // Return -1 for invalid day names
}

int main() {
    cout << dayNumToName(1) << endl;
    cout << dayNameToNum("Mon") << endl;
    cout << dayNameToNum("Tue") << endl;
    cout << dayNameToNum("Monday") << endl; // Invalid input
    cout << dayNameToNum("monday") << endl;

    system("pause");
    return 0;
}
