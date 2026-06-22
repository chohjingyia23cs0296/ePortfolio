//aggregation is a special type of association which is one way relationship
#include <iostream>
#include <string>
using namespace std; // Using namespace std
// Aggregated class
class Address {
private:
    string street;
    string city;
    string zipCode;
public:
    Address(const string& street, const string& city, const string& zipCode)
        : street(street), city(city), zipCode(zipCode) {}
    void display() const {
        cout << street << ", " << city << ", " << zipCode << endl;
    }
};
// Aggregator class
class Person {
private:
    string name;
    Address address; // Aggregation
public:
    Person(const string& name, const Address& address)
        : name(name), address(address) {}
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: ";
        address.display();
    }
};
int main() {
    Address addr("123 Main St", "Cityville", "12345");
    Person person("John Doe", addr);
    person.display();
  
    return 0;
}
