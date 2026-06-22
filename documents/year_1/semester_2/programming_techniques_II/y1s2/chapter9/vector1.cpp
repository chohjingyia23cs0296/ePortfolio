#include <iostream>
#include <vector>
using namespace std;

// Topic 10 >> Containers, e.g., vector
class Point {
private:
    int x, y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
    void set(int _x, int _y) {
        x = _x;
        y = _y;
    }
    
    int getX() const { return x; }
    int getY() const { return y; }
};

int menu() {
    cout << endl;
    cout << "1. Add point" << endl;
    cout << "2. Remove last point" << endl;
    cout << "3. Edit point" << endl;
    cout << "4. Print list" << endl;
    cout << "5. Exit" << endl;
    cout << endl;
    cout << "Choose an operation from 1 to 5 => ";
    
    int choice;
    cin >> choice;
    
    cout << endl;
    
    return choice;
}

int main() {
    vector<Point> list;
    list.push_back(Point(1, 2));
    list.push_back(Point(31, 2));
    list.push_back(Point(13, 32));

    int c = menu();
    int x, y;
    int index;

    while (c != 5) {
        switch (c) {
        case 1: // add a new item at the back of the list
            cout << "Enter x and y => ";
            cin >> x >> y;
            list.push_back(Point(x, y));
            cout << "Number of items in the list now is " << list.size() << endl;
            break;

        case 2: // Remove the last item from the list
            if (!list.empty()) {
                list.pop_back();
                cout << "Number of items in the list now is " << list.size() << endl;
            } else {
                cout << "The list is already empty." << endl;
            }
            break;

        case 3: // Edit the item at index
            cout << "Enter item's index to edit => ";
            cin >> index;
            if (index >= 0 && index < list.size()) {
                cout << endl;
                cout << "Current x and y: " << list[index].getX() << " , " << list[index].getY() << endl;
                cout << "Enter new x and y => ";
                cin >> x >> y;
                list[index].set(x, y);
            } else {
                cout << "Invalid index." << endl;
            }
            break;

        case 4: // Print all items in the list
            for (size_t i = 0; i < list.size(); i++) {
                cout << (i + 1) << ".\t x=" << list[i].getX() << ", y=" << list[i].getY() << endl;
            }
            cout << endl;
            break;

        default:
            cout << "Invalid choice. Please choose again." << endl;
            break;
        }

        c = menu();
    }

    return 0;
}
