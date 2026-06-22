#include<iostream>
using namespace std;

class Money{
    public:
    int amount;
    Money(int a):amount(a){};
    int getAmount(){
        return amount;
    }


};
class Wallet{
    private:
    Money *money;
    public:
    Wallet(Money *m):money(m){};
    void showMoney(){
        if(money!=nullptr){
            cout<<"Money; "<<money->getAmount();
        }
        else{
            cout<<"MOney 0";
        }
    }
};
int main(){
    Money *money=new Money(100);
    Wallet w(money);
    w.showMoney();

}