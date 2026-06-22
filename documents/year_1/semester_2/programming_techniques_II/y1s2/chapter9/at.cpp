#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;
    return 0;
}
