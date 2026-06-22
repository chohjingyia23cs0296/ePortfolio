
#include<iostream>
using namespace std;
class Fraction{
    private:int num;
    int denom;
    public:
    void setNum(int newNum){
        num=newNum;
    }
    void setDenom(int newDenom){
        denom=newDenom;
    }
    Fraction multiply(const Fraction&other){
        Fraction result;
        result.num=num*other.num;
        result.denom=denom*other.denom;
        return result;
    }
    Fraction add(const Fraction&other){
        Fraction result;
        result.num=num*other.denom+other.num*denom;
        result.denom=denom*other.denom;
        return result;
    }
    Fraction substract(const Fraction&other){
        Fraction result;
        result.num=num*other.denom-other.num*denom;
        result.denom=denom*other.denom;
        return result;
    }
    Fraction divide(const Fraction& other){
        Fraction result;
        result.num=num*other.denom;
        result.denom=denom*other.num;
        return result;
    }
    void readFrac(){
        char clash;
        cout<<"Enter numerator / denominator: ";
        cin>>num>>clash>>denom;
    }
    void displayFrac(){
        cout<<num<<"/"<<denom;
    }
    int getNum(){
        return num;
    }
    int getDenom(){
        return denom;
    }
    

};
int main()
{
    Fraction f1,f2,f3;
    cout<<"Enter 1st fraction: "<<endl;
    f1.readFrac();
    cout<<"Enter 2nd fraction: "<<endl;
    f2.readFrac();

    f3=f1.multiply(f2);
    cout<<f1.getNum()<<"/"<<f1.getDenom()<<"*"<<f2.getNum()<<"/"<<f2.getDenom()<<"=";
    f3.displayFrac();
    cout<<endl;

    f3=f1.divide(f2);
     cout<<f1.getNum()<<"/"<<f1.getDenom()<<"/"<<f2.getNum()<<"/"<<f2.getDenom()<<"=";
    f3.displayFrac();
    cout<<endl;

    f3=f1.add(f2);
     cout<<f1.getNum()<<"/"<<f1.getDenom()<<"+"<<f2.getNum()<<"/"<<f2.getDenom()<<"=";
    f3.displayFrac();
    cout<<endl;

    f3=f1.substract(f2);
     cout<<f1.getNum()<<"/"<<f1.getDenom()<<"-"<<f2.getNum()<<"/"<<f2.getDenom()<<"=";
    f3.displayFrac();
    cout<<endl;

    return 0;
}