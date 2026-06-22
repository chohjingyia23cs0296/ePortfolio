#include <iostream>
using namespace std;

class Chapter{
    private:
    int pages;
    public:
    Chapter(int p):pages(p){};
    int getPages(){
        return pages;
    }
};
class Book{
    private:
    Chapter c1,c2,c3,c4;
    public:
    Book(int pages1,int pages2,int pages3,int pages4):c1(pages1),c2(pages2),c3(pages3),c4(pages4){};
    void showPages(){
        cout<<"Pages: "<<c1.getPages()<<c2.getPages()<<c3.getPages();
    }

};
int main(){
    Book myBook(20,30,40,50);
    myBook.showPages();

}