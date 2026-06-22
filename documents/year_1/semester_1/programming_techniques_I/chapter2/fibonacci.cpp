#include <iostream>

int main() {
    int n, first, second, next;

    std::cout << "Enter the number of terms you want: " << std::endl;
    std::cin >> n;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> first;

    std::cout << "Enter the second number: " << std::endl;
    std::cin >> second;

    std::cout << "First " << n << " terms of Fibonacci series are:- " << std::endl;

    int count = 0;
    while (count < n) {
        if (count == 0)
            next = first;
        else if (count == 1)
            next = second;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        std::cout << next << std::endl;
        count++;
    }

    return 0;
}
