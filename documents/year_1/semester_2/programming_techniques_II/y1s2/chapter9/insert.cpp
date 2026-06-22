#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.insert(vec.begin() + 2, 99); // Insert 99 at index 2
    for(auto it=vec.begin();it!=vec.end();it++) {
        std::cout << *it << " "; // Output: 1 2 99 3 4 5
    }
    std::cout << std::endl;
    return 0;
}
