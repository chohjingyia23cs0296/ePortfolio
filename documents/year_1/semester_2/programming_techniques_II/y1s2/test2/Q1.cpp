#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Name {
private:
    string firstname;
    string lastname;
public:
    Name(string first, string last) : firstname(first), lastname(last) {}

    string getFullName() const {
        return firstname + " " + lastname;
    }
};

class Product {
private:
    string name;
    string category;
    double price;
    int quantity;

public:
    Product() : name(""), category(""), price(0), quantity(0) {}

    Product(string n, string c, double p) : name(n), category(c), price(p), quantity(0) {}

    string getName() const {
        return name;
    }

    string getCategory() const {
        return category;
    }

    double getPrice() const {
        return price;
    }

    double getQuantity() const {
        return quantity;
    }

    void setQuantity(double q) {
        quantity = q;
    }
};

class Customer {
private:
    Name customerName;
    string address;
    int numProduct;
    Product *product;

public:
    Customer(string first, string last, string addr)
        : customerName(first, last), address(addr), numProduct(0), product(nullptr) {}

    ~Customer() {
        delete[] product;
    }

    void buy(const Product& products, int numProduct) {
        if (numProduct >= 10) { 
            cout << "Sorry!! You already reached the maximum number of products purchased." << endl;
        } else {
            product[numProduct++] = products;
        }
    }

    void print() {
        cout << "Name:       " << customerName.getFullName() << endl;
        cout << "Address:    " << address << endl;
        cout << "Number of product purchased:  " << numProduct << endl << endl;
        cout << setw(4) << "No" << setw(20) << "Product Name" << setw(15) << "Category" << setw(10) << "Quantity" << setw(15) << "Unit Price(RM)" << setw(15) << "Amount(RM)" << endl;
        double totalPrice = 0.0;

        for (int i = 0; i < numProduct; i++) {
            const Product& prod = product[i];
            double amount = prod.getPrice() * prod.getQuantity();
            totalPrice += amount;
            cout << setw(4) << i + 1 << setw(20) << prod.getName() << setw(15) << prod.getCategory() << setw(10) << prod.getQuantity() << setw(15) << prod.getPrice() << setw(15) << amount << endl;
        }

        cout << "Total price= RM " << totalPrice << endl;
    }
};

int main() {
    Customer cust("Amir", "Jalil", "Masai, Johor");

    Product p1("Jacob", "Biscuit", 14.8);
    Product p2("Twister", "Drink", 7.5);
    Product p3("Ayamas", "Nugget", 18.4);
    Product p4("Oreo", "Biscuit", 3.8);

    cust.buy(p4, 5);
    cust.buy(p2, 4);
    cust.buy(p3, 2);
    cust.buy(p1, 3);

    cust.print();
    cout<<"hudfh";
    return 0;
}

