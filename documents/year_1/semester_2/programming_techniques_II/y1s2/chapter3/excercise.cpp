#include<iostream>
#include <iomanip>
using namespace std;

class Product{
private:
    int code;
    double price;
public:
	Product() : code(0), price(0.0) {}
    Product(int c, double p){
        code = c;
        price = p;
    }
    void setCode(int c){
        code = c;
    }
    void setPrice(double p){
        price = p;
    }
    int getCode()const{
        return code;
    }
    double getPrice()const{
        return price;
    }
};

const int MAX_PRODUCT = 100;

int main(){
    int productNum = 0;
    double totalPrice = 0.0;
    double avgPrice=0.0;
    Product productList[MAX_PRODUCT];

    cout << "How many products to enter? ";
    cin >> productNum;
    
	cout << "\n";
    for(int i = 0; i < productNum; i++){
        int code;
        double price;
		
        cout << "Enter the information of product #" << (i + 1) << endl;
        cout << "Product Code: ";
        cin >> code;
        productList[i].setCode(code);

        cout << "Price: ";
        cin >> price;
        productList[i].setPrice(price);
        cout << "\n";
    }

    //productList[productNum] = Product(100, 1.00);
    //productNum++;

    cout <<left<<setw(10)<<"No" <<left<< setw(15) << "Product Code" << left<<setw(15) << "Price"<<endl<<endl;
    for(int i = 0; i < productNum; i++){
        cout <<left<<setw(10)<<(i + 1) << left << setw(15) << fixed<<setprecision(2)<<productList[i].getCode() << left << setw(15) << fixed<<setprecision(2)<<productList[i].getPrice() << "\n";
        avgPrice += productList[i].getPrice()/productNum;
    }

    cout << "\nAverage Price:    RM " << fixed<<setprecision(2)<<avgPrice << endl;

    return 0;
}

