#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1(10, 1); // vector of 10 elements initialized to 1
    std::vector<int> vec2;
    vec2 = vec1; // assignment
    std::cout << "vec2 size after assignment: " << vec2.size() << std::endl;//10
    return 0;
}
