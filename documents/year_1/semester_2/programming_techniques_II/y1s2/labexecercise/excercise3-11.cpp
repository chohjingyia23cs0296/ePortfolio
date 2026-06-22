#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string registrar;
    string country;
public:
    Address() : registrar(""), country("") {}
    void set(string r, string c) {
        registrar = r;
        country = c;
    }
    string getRegistrar() const {
        return registrar;
    }
    string getCountry() const {
        return country;
    }
};

class Ship {
private:
    string name;
    string yearMade;
    Address address;
public:
    Ship() : name(""), yearMade("") {}
    void read() {
        cout << "\n<<< Enter the information of the ship >>>\n";
        cout << "Ship Name: ";
        getline(cin, name);
        cout << "Year built: ";
        getline(cin, yearMade);
        string registrar, country;
        cout << "The address the ship was registered:\n";
        cout << "Registrar Office: ";
        getline(cin, registrar);
        cout << "Country: ";
        getline(cin, country);
        address.set(registrar, country);
    }
    void print() const {
        cout << "Ship Name: " << name << endl;
        cout << "Year built: " << yearMade << endl;
        cout << "Registered at:\n";
        cout << "   " << address.getRegistrar() << ", " << address.getCountry() << endl;
    }
};

int main() {
    const int MAXSHIP = 10;
    Ship* ships = new Ship[MAXSHIP];
    int addShip = 0;
    int choice;

    do {
        cout << "======== MENU ========" << endl;
        cout << "1. Add a ship" << endl;
        cout << "2. Display ships" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an operation => ";
        cin >> choice;
        cin.ignore(); // to consume the newline character left by cin

        if (choice == 1) {
            if (addShip < MAXSHIP) {
                ships[addShip].read();
                addShip++;
            } else {
                cout << "Maximum number of ships reached. Cannot add more ships." << endl;
            }
            cout << "Press any key to continue . . ." << endl;
    cin.get();
        } else if (choice == 2) {
        cout<<"<<< Inventory of ships >>>\n";
        cout<<"Total ships: "<<addShip<<endl;
        cout<<"==== Ship List ====\n";
            for (int i = 0; i < addShip; i++) {
                ships[i].print();
                cout<<endl;
            }
            cout << "Press any key to continue . . ." << endl;
    cin.get();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (true);

    delete[] ships;
    return 0;
}