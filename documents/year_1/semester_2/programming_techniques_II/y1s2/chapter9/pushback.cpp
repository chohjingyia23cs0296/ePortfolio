#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;

    // Adding elements to the vector using push_back
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Printing the elements of the vector
    for (int number : numbers) {
        cout << number << " ";
    }

    return 0;
}
