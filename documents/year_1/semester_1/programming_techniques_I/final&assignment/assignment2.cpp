#include <iostream>
using namespace std;


void displayAccountInfo(string accountholder,int accountnum,int &balance);
void deposit(int depositamount,int &balance);
void withdraw(int withdrawamount,int &balance);

int main(){
    int accountnum = 1013202341;
    string accountholder = "User 1";
    int balance=200;
    int depositamount=500;
    int withdrawamount=200;
    char choice;

    do{
    cout<<"<<<<<<<<My Accounts Overview >>>>>>>>"<<endl;
    displayAccountInfo(accountholder, accountnum, balance);
    cout<<endl;
    cout<<"<<<<<<<< Deposit Transaction >>>>>>>>"<<endl;
    deposit(depositamount,balance);
    cout<<endl;
    cout<<"<<<<<<<< Withdrawal Transaction >>>>>>>>"<<endl;
    withdraw(withdrawamount,balance);
    cout<<endl;
    cout<<"<<<<<<<< My Accounts Overview >>>>>>>>"<<endl;
    displayAccountInfo(accountholder, accountnum, balance);
    cout<<endl;
    cout<<"Do you want to perform another transaction> (Y/N): ";
    cin>>choice;
    }while(choice!='N'&&choice!='n');
    return 0;
}
void displayAccountInfo(string accountholder,int accountnum,int &balance){
    cout<<"Account Holder Name: "<<accountholder<<endl;
    cout<<"Account Number: "<<accountnum<<endl;
    cout<<"Balance:RM "<<balance<<endl;
}
void deposit(int depositamount,int &balance){

    balance+=depositamount;
    cout<<"Deposit of RM "<<depositamount<<" successful."<<endl;
}
void withdraw(int withdrawamount,int &balance){

    balance-=withdrawamount;
    cout<<"Withdrawal of RM "<<withdrawamount<<" successful."<<endl;
}