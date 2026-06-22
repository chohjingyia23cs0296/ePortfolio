#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.erase(vec.begin() + 2); // Erase element at index 2
    for(int v : vec) {
        std::cout << v << " "; // Output: 1 2 4 5
    }
    std::cout << std::endl;
    return 0;
}
