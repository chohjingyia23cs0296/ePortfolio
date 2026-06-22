#include<iostream>
#include<vector>
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
    string title;
    vector<Chapter>chapter;
    public:
    Book(string t,vector<int>pages):title(t){
        for(int page:pages){
            chapter.push_back(Chapter(page));
        }
    }
    int totalPages(){
        int total=0;
        for(Chapter&c:chapter){
            total+=c.getPages();
        }
    }
    string getTitle(){
        return title;
    }
};
class Library{
    private:
    vector<Book> book;
    public:
    void addBooks(Book b){
        book.push_back(b);
    }
    void showBooks(){
        for(Book&b:book){
            cout<<"Books: "<<b.getTitle()<<" with "<<b.totalPages()<<endl;
        }
    }
};
class Author{
    private:
    string name;
    vector<Book*>book;
    public:
    Author(string n):name(n){};
    void writeBook(Book*b){
        book.push_back(b);
    }
    void showBook(){
        for(Book*b:book){
            cout<<b->getTitle()<<" by "<<name<<endl;
        }
    }
};
int main() {
    vector<int> pages = {10, 20, 30};
    Book b1("C++ Programming", pages);
    Book b2("Data Structures", pages);

    Author a("John Doe");
    a.writeBook(&b1);
    a.writeBook(&b2);
    a.showBook();

    Library lib;
    lib.addBooks(b1);
    lib.addBooks(b2);
    lib.showBooks();

    return 0;
}