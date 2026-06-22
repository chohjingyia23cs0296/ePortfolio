#include <iostream>
#include <string>

int main() {
    // Define an initial string
    std::string str = "Hello";

    // Append " World" to the string
    str.append(" World");

    // Replace "World" with "Universe"
    size_t pos = str.find("World");
    if (pos != std::string::npos) {
        str.replace(pos, 5, "Universe");
    }

    // Output the modified string
    std::cout << "Modified string: " << str << std::endl;

    return 0;
}
