#include <iostream>

class Integer {
private:
    int value;

public:
    Integer(int v) : value(v) {}

    // Overload prefix increment operator++
    Integer& operator++() {
        ++value;
        return *this;
    }

    // Overload prefix decrement operator--
    Integer& operator--() {
        --value;
        return *this;
    }

    // Function to get the value of the integer
    int getValue() const {
        return value;
    }
};

int main() {
    Integer num(5);

    std::cout << "Original value: " << num.getValue() << std::endl;

    // Use prefix increment operator++
    ++num;
    std::cout << "After prefix increment: " << num.getValue() << std::endl;

    // Use prefix decrement operator--
    --num;
    std::cout << "After prefix decrement: " << num.getValue() << std::endl;

    return 0;
}
