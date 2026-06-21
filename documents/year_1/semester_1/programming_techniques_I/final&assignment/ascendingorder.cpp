#include <iostream>

int main() {
    int num1, num2;

    // Input the first number
    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    // Input the second number
    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    if (num1 <= num2) { // Changed to <=
        // Numbers in ascending order
        int current = num1; // Initialize current to num1
        while (current <= num2) { // Changed to <=
            std::cout << current << " ";
            current++;
        }
    } else if (num1 > num2) {
        // Numbers in descending order
        int current = num1; // Initialize current to num1
        while (current >= num2) { // Changed to >=
            std::cout << current << " ";
            current--;
        }
    } else {
        std::cout << "No numbers between the two integers.";
    }

    std::cout << std::endl;

    return 0;
}
