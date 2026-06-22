#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;//0
   
}
