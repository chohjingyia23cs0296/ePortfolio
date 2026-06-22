#include<iostream>
#include<iomanip>
using namespace std;

class TennisShop {
protected:
    string brand;
    double price;
    int quantity;
public:
    TennisShop() {}
    TennisShop(int q) : quantity(q) {}
    void setBrandPrice(string b, double p) {
        brand = b;
        price = p;
    }
    string getBrand() {
        return brand;
    }
    double getPrice() {
        return price;
    }
    int getQuantity() {
        return quantity;
    }
    virtual void display() = 0;
    virtual double calcPrice() = 0;
};

class Customer {
private:
    string CustName;
    TennisShop* itemsList[10];
    int numOfitem;
public:
    Customer(string customerName) : CustName(customerName), numOfitem(0) {}
    string getName() {
        return CustName;
    }
    void buy(TennisShop* item) {
        if (numOfitem < 10) {
            itemsList[numOfitem++] = item;
        } else {
            cout << "Items are full\n";
        }
    }
    void print() {
        double total=0.0;
        cout << "LIST OF TENNIS ITEMS BOUGHT" << endl;
        for (int i = 0; i < numOfitem; i++) {
            cout << "-----Item #" << i + 1 << "------\n";
            itemsList[i]->display();
            total+=itemsList[i]->calcPrice();
            cout << "\n";
        }
        cout<<"TOTAL: RM "<<fixed << setprecision(2) <<total<<endl;
    }
};

class Racket : public TennisShop {
private:
    int racketType;
public:
    Racket() {}
    Racket(int racket, int _quantity) : racketType(racket), TennisShop(_quantity) {
        switch (racketType) {
        case 1: brand = "Wilson"; price = 569.70; break;
        case 2: brand = "Yonex"; price = 719.70; break;
        case 3: brand = "Yonex"; price = 1289.70; break;
        case 4: brand = "Dunlop"; price = 989.70; break;
        default: brand = "Unknown"; price = 0.0;
        }
    }
    double calcPrice() override {
        return price * quantity;
    }
    void display() override {
        string racketName;
        switch (racketType) {
        case 1: racketName = "Junior Tennis Racket"; break;
        case 2: racketName = "Beginners Tennis Racket"; break;
        case 3: racketName = "Advanced Tennis Racket"; break;
        case 4: racketName = "All Tennis Racket"; break;
        default: racketName = "Unknown";
        }
        cout << "Tennis Racket\n";
        cout << "Brand       : " << brand << "\n";
        cout << "Description : " << racketName << endl;
        cout << "Price       : RM" << fixed << setprecision(2) << price << endl;
        cout << "No Discount!\n";
        cout << "Quantity    : " << quantity << endl;
        cout << "Subtotal    : RM " << fixed << setprecision(2) << calcPrice() << endl;
    }
};

class Ball : public TennisShop {
private:
    int numBalls;
    int ballId;
public:
    Ball() {}
    Ball(int id, int _quantity) : ballId(id), TennisShop(_quantity) {
        switch (ballId) {
        case 1: brand = "Wilson"; price = 38.40; numBalls = 4; break;
        case 2: brand = "Wilson"; price = 28.80; numBalls = 3; break;
        case 3: brand = "Dunlop"; price = 81.00; numBalls = 4; break;
        case 4: brand = "Dunlop"; price = 33.00; numBalls = 3; break;
        default: brand = "Unknown"; price = 0.0; numBalls = 0;
        }
    }
    double calcDisc() {
        return price * quantity * 0.15;
    }
    double calcPrice() override {
        return price * quantity - calcDisc();
    }
    void display() override {
        string ballName;
        switch (ballId) {
        case 1: ballName = "Roland Garros All Court"; break;
        case 2: ballName = "US Open"; break;
        case 3: ballName = "Fort Max TP KNLTB"; break;
        case 4: ballName = "Fort All Court"; break;
        default: ballName = "Unknown";
        }
        cout << "Tennis Ball\n";
        cout << "Brand       : " << brand << "\n";
        cout << "Description : " << ballName << endl;
        cout << "Price       : RM" << fixed << setprecision(2) << price << " for " << numBalls << " balls per tube\n";
        cout << "Discount    : 15.00%\n";
        cout << "Quantity    : " << quantity << endl;
        cout << "Subtotal    : RM " << fixed << setprecision(2) << calcPrice() << endl;
    }
};

int displayMainMenu() {
    int choice;
    cout << "==========[MENU]============" << endl;
    cout << "  [1] Buy item" << endl;
    cout << "  [2] Print all items" << endl;
    cout << "  [3] Exit" << endl;
    cout << "============================" << endl;
    cout << "Choice: ";
    cin >> choice;
    return choice;
}

int displayRacketMenu() {
    int choice;
    cout << "*** Racket ***" << endl;
    cout << "  [1] Wilson: Junior Tennis Racket" << endl;
    cout << "  [2] Yonex: Beginners Tennis Racket" << endl;
    cout << "  [3] Yonex: Advanced Tennis Racket" << endl;
    cout << "  [4] Dunlop: All Tennis Racket" << endl;
    cout << "Choice: ";
    cin >> choice;
    return choice;
}

int displayBallMenu() {
    int choice;
    cout << "*** Ball ***" << endl;
    cout << "  [1] Wilson: Roland Garros All Court" << endl;
    cout << "  [2] Wilson: US Open" << endl;
    cout << "  [3] Dunlop: Fort Max TP KNLTB" << endl;
    cout << "  [4] Dunlop: Fort All Court" << endl;
    cout << "Choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Customer customer("ARIF AIMAN");
    double total=0.0;
    while (true) {
        int mainChoice = displayMainMenu();
        if (mainChoice == 1) {
            cout << "<< Item to buy >>" << endl;
            cout << "  [1] Racket" << endl;
            cout << "  [2] Ball" << endl;
            cout << "Choice: ";
            int itemChoice;
            cin >> itemChoice;

            int itemMenuChoice;
            int quantity;
            if (itemChoice == 1) {
                itemMenuChoice = displayRacketMenu();
                cout << "Quantity: ";
                cin >> quantity;
                Racket* racket = new Racket(itemMenuChoice, quantity);
                customer.buy(racket);
            } else if (itemChoice == 2) {
                itemMenuChoice = displayBallMenu();
                cout << "Quantity: ";
                cin >> quantity;
                Ball* ball = new Ball(itemMenuChoice, quantity);
                customer.buy(ball);
                
            }
        } else if (mainChoice == 2) {
            customer.print();
            cout << "\n";
        } else if (mainChoice == 3) {
            cout << "Thank you for using this system ;)" << endl;
            break;
        } else {
            cout << "Invalid input. Try again!" << endl;
        }
    }
    return 0;
}
