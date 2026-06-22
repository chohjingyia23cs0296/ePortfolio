#include <iostream>
using namespace std;

// Function to calculate volume directly
int volume(int width, int length, int height) {
    return width * height * length;
}

// Curried function to calculate volume step by step
auto curriedVolume(int width) {
    return [width](int length) {
        return [width, length](int height) {
            return width * length * height;
        };
    };
}

int main() {
    // Calculate volume directly
    cout << "Volume1: " << volume(2, 5, 10) << endl;

    // Calculate volume using curried function
    cout << "Volume2: " << curriedVolume(2)(5)(10) << endl;

    // Partial application example
    auto a = curriedVolume(2);
    auto b = a(5);
    cout << "Volume3: " << b(10) << endl;

    cin.get();
}
