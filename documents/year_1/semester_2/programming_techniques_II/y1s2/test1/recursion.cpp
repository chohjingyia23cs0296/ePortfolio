//recursion is a technique that uses function to call themselves
#include<iostream>
using namespace std;

// Function to calculate sum using iteration
int sumNumbers(int m, int n) {
    int sum = 0;
    for(int i = m; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Recursive function to calculate sum
int recursiveSumNumbers(int m, int n) {
    if(m == n)
        return m;
    return m + recursiveSumNumbers(m + 1, n);
}

int main() {
    // Calculate sum using iteration
    cout << "Sum1: " << sumNumbers(1, 5) << endl;

    // Calculate sum using recursion
    cout << "Sum2: " << recursiveSumNumbers(1, 5) << endl;

    return 0;
}
