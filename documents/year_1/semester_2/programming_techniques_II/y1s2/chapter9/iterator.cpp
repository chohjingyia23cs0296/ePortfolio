#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Define a class Point to represent points in 2D space
class Point {
private:
    int x, y;  // x and y coordinates

public:
    // Constructor with default values for x and y
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Getter for x coordinate
    int getX() const { return x; }
    // Getter for y coordinate
    int getY() const { return y; }
};

int main() {
    // Vector of integers
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // Iterating over vector without using an iterator
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << "\t";
    cout << endl;

    // Iterating over vector using an iterator
    vector<int>::iterator i;
    for (i = numbers.begin(); i != numbers.end(); i++)
        cout << *i << "\t";
    cout << endl;

    // Vector of Point objects
    vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(11, 22));
    points.push_back(Point(41, 32));

    // Iterating over vector of Point objects without using an iterator
    for (int i = 0; i < points.size(); i++)
        cout << "x=" << points[i].getX() << "\ty=" << points[i].getY() << endl;

    // Iterating over vector of Point objects using an iterator
    vector<Point>::iterator p;
    for (p = points.begin(); p != points.end(); p++)
        cout << "x=" << p->getX() << "\ty=" << p->getY() << endl;

    // Map of string to int
    map<string, int> days;
    days["mon"] = 1;
    days["tue"] = 2;

    // Map of int to string
    map<int, string> hari;
    hari[1] = "isnin";
    hari[5] = "jumaat";

    // Iterating over map of string to int
    map<string, int>::iterator d;
    for (d = days.begin(); d != days.end(); d++)
        cout << d->first << "\t" << d->second << endl;

    // Iterating over map of int to string
    map<int, string>::iterator h;
    for (h = hari.begin(); h != hari.end(); h++)
        cout << h->first << "\t" << h->second << endl;

    // Pause the system for user to see result
    system("pause");
    return 0;
}
