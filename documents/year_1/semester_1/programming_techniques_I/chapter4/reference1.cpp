#include <iostream>
using namespace std;

void test(int&, int&, int, int&);

int main()
{
    int a, b, c, d;
    a = 3; b = 4; c = 20; d = 78;

    cout << a << " " << b << " " << c << " " << d << endl;

    // Call test function with a, b, c, and d as parameters
    test(a, b, c, d);

    // Output the values of a, b, c, and d after the first call to test
    cout << a << " " << b << " " << c << " " << d << endl;

    // Modify d using the expression d = a * b + c - d
    d = a * b + c - d;

    // Call test function with updated a, b, c, and d as parameters
    test(a, b, c, d);

    // Output the values of a, b, c, and d after the second call to test
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

// Define the test function
void test(int& a, int& b, int c, int& d)
{
    // Input new values for a, b, c, and d
    cin >> a >> b >> c >> d;

    // Modify c using the expression c = a * b + d - c
    c = a * b + d - c;

    // Modify c using the expression c = 2 * c
    c = 2 * c;
}
