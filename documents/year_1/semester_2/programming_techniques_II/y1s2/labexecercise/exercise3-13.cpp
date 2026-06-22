#include <iostream>
using namespace std;

class Contact {
private:
    string phone;
public:
    Contact(string p) : phone(p) {}

    string getPhone() const {
        return phone;
    }
};

class Car {
private:
    string plate;
public:
    Car(string p) : plate(p) {}

    string getPlate() const {
        return plate;
    }
};

class Customer {
private:
    string name;
    Car* car;
    Contact contact;
public:
    Customer(string n, string p) : name(n), contact(p), car(nullptr) {}

    string getName() const {
        return name;
    }

    string getPhoneNum() const {
        return contact.getPhone();
    }

    void printInfo() const {
        cout << "Customer Name: " << name <<endl;
        cout<< "Phone Number:  " << getPhoneNum()<<endl;
        cout << "Rented Car:   " << car->getPlate()<<endl;
    }
};

int main() {

    Customer cust1("Ahmad Kamal", "015-75769800");
    Customer cust2("Siti Nurdiana Abdullah", "014-8889900");
    Car car1("JSP245");
    Car car2(" ");

    cout << "Customer's Name:"<< cust1.getName() <<endl;
    cout<< "Phone Number    :"<< cust1.getPhoneNum()<<endl;
    cout << "Rented Car     :"<< car1.getPlate()<<endl;

    cout<<"\n";

    cout << "Customer's Name: " << cust2.getName() <<endl;
    cout << "Phone Number   :  " << cust2.getPhoneNum()<<endl;
    cout << "Rented Car     :   " << car2.getPlate()<<endl;

    return 0;
}
