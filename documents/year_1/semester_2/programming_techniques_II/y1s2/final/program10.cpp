#include<iostream>
using namespace std;

int displayMainMenu() {
int choice;
cout << "==========[MENU]============\n"
<< " [1] Buy item\n"
<< " [2] Print all items\n"
<< " [3] Exit\n"
<< "============================\n"
<< "Choice: ";
cin >> choice;
return choice;
}

int displayRacketMenu() {
int choice;
cout << " [1] Wilson: Junior Tennis Racket\n"
<< " [2] Yonex: Beginners Tennis Racket\n"
<< " [3] Yonex: Advanced Tennis Racket\n"
<< " [4] Dunlop: All Tennis Racket\n"
<< "Choice: ";
cin >> choice;
return choice;
}

int displayBallMenu() {
int choice;
cout << " [1] Wilson: Roland Garros All Court\n"
<< " [2] Wilson: US Open\n"
<< " [3] Dunlop: Fort Max TP KNLTB\n"
<< " [4] Dunlop: Fort All Court\n"
<< "Choice: ";
cin >> choice;
return choice;
}

class TennisShop {
    protected:
string brand;
double price;
int quantity;
    public:
TennisShop() {}
TennisShop(int quantity) {
this->quantity = quantity;
}
void setBrandPrice(string brand, double price) {
this->price = price;
this->brand = brand;
}
string getBrand() { return brand; }
double getPrice() { return price; }
int getQuantity() { return quantity; }
virtual void display() = 0;
virtual double calcPrice() = 0;
};

class Racket:public TennisShop{
    private:
    int racketType;
    public:
    Racket(){};
    Racket(int rT,int _quantity):TennisShop(_quantity){
        racketType=rT;
    }
    void display()override{
        string name;
        if(racketType==1){
            name="Junior Tennis Racket";
            brand="Wilson";
            price=569.70;
        }else if(racketType==2){
            name="Beginners Tennis Racket";
            brand="Yonex";
            price=719.70;
        }else if(racketType==3){
            name="Advanced Tennis Racket";
            brand="Yonex";
            price=1289.70;
        }
        else if(racketType==4){
            name="All Tennis Racket";
            brand="DunLop";
            price=989.70;
        }
        cout<<"Tennis racket\n";
        cout<<"Brand : "<<brand<<endl;
        cout<<"Type : "<<name<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"No Discount!\n";
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Subtotal: "<<calcPrice()<<"\n\n";

    }
    double calcPrice()override{
        return quantity*price;
    }
};
class Ball:public TennisShop{
    private:
    int numBalls;
    int ballId;
    public:
    Ball();
    Ball(int numB, int ballid):numBalls(numB),ballId(ballid){};
    double calcPrice()override{
        return calcDisc()*0.85;
    }

    double calcDisc(){
        return numBalls*price;
    }
    void display()override{
        string description;
        if(ballId==1){
            brand="Wilson";
            description="Roland Garros All Court";
            price=38.40;
            numBalls=4;
        }else if(ballId==2){
            brand="Wilson";
            description="US Open";
            price=28.80;
            numBalls=3;
        }else if(ballId==3){
            brand="Dunlop";
            description="Fort Max TP KNLTB";
            price=81.00;
            numBalls=4;
        }else if(ballId==4){
            brand="Dunlop";
            description="Fort All Court";
            price=33.00;
            numBalls=3;
        }
        cout<<"Tennis Ball\n";
        cout<<"Brand : "<<brand<<endl;
        cout<<"Description: "<<description<<endl;
        cout<<"Price : RM"<<price<<" for "<<"Balls per tube\n";
        cout<<"Discount : 15.00%\n";
        cout<<"Quantity : "<<quantity<<endl;
        cout<<"Subtotal : "<<calcDisc()<<"\n\n";
    }
};

class Customer{
    private:
    string custName;
    TennisShop*itemList[10];
    int numOfItem=0;
    public:
    Customer(string cN):custName(cN){};
    string getName(){
        return custName;
    }
    void buy(TennisShop *iL){
        if(numOfItem<10){
            itemList[numOfItem++]=iL;
        }else{
             cout<<"num of list is full\n";
        }
    }
    void print(){
        double TOTAL=0.0;
        cout<<"LIST OF TENNIS ITEMS BOUGHT\n\n";

        for(int i=0;i<numOfItem;i++){
            cout<<"----- Item "<<i+1<<" -----\n";
            itemList[i]->display();
            TOTAL+=itemList[i]->calcPrice();
        }
        cout<<"TOTAL :RM "<<TOTAL<<endl;
    }
};

int main() {
    TennisShop *p;
    Customer c("ARIF AIMAN");
    cout<<"WELCOME"<<c.getName()<<"\n\n";
    do{
        int choice=displayMainMenu();
        switch(choice){
            case 1:
            int mainchoice;
            cout<<"<< Item to buy >>\n";
            cout<<"[1] Racket\n[2] Ball\n";
            cout<<"Choice: ";
            cin>>mainchoice;
            if(mainchoice==1){
                int quantityracket=0;
                int racketMenu=displayRacketMenu();
                cout<<"Quantity : ";
                cin>>quantityracket;
                p=new Racket(racketMenu,quantityracket);
                c.buy(p);

            }else if(mainchoice==2){
                int ballquantity=0;
                int ballMenu=displayBallMenu();
                cout<<"Quantity : ";
                cin>>ballquantity;
                p=new Ball( ballquantity,  ballMenu);
                c.buy(p);

            }else{
                cout<<"Invalid output\n";
            }
            break;
        case 2:
        c.print();
        
        break;

        case 3:
        cout<<"Thank you for using this system ;)\n";
        return 0;
        break;
        default:
        cout<<"Invalid input. Try again!\n";
        }
    }while(true);
}

