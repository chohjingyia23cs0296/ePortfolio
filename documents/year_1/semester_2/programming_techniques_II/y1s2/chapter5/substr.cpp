#include <iostream>
#include <string>
using namespace std;

int main() {
  string b = "Hello, World!";
   string a = b.substr(4, 5); // Extract substring starting from index 7 with length 5
cout << "Substring: " << a << endl; // Output: "World"
    return 0;
}
