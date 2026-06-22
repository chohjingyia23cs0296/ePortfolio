#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3, 4, 5, 3}; // 3 is a duplicate
    s.insert(6);
    s.insert(2); // Duplicate insert

    for(int val : s) {
        std::cout << val << " "; // Output: 1 2 3 4 5 6
    }
    std::cout << std::endl;
    return 0;
}
