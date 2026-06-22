#include <iostream>
using namespace std;

class Chapter {
private:
    int nPages;
public:
    Chapter(int pages) {
        nPages = pages;
    }
    int getPages() {
        return nPages;
    }
};

class Book {
public:
    Chapter c1, c2, c3, c4;
    Book(int pages1, int pages2, int pages3, int pages4)
        : c1(pages1), c2(pages2), c3(pages3), c4(pages4) {}
    void showNumberofPages() {
        cout << "Total number of pages: " << (c1.getPages() + c2.getPages() + c3.getPages() + c4.getPages()) << endl;
    }
};

int main() {
    Book pt2(200, 190, 50, 100);
    pt2.showNumberofPages();
    
    return 0;

}
