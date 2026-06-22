#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    double price; // The price for each item purchased
    int item; // The count for each item purchased
    double totalPayment=0.0; // The total amount of payment
    double highestPrice=0.0;
    double maxprice; // The price of the most expensive item
    // purchased by the customer.

 cout << showpoint << fixed << setprecision(2);

    while(true){
        cout << "Enter the item's price: ";
        cin >> price;
        if(price==0){
            break;
        }
        cout << "Enter the number of item: ";
        cin >> item;
        
        totalPayment+=price*item;
        cout<<"\n";
        if(price>maxprice){
            maxprice=price;
        }
    }
    cout<<"Total Payment:RM "<<totalPayment<<endl;
    cout<<"The price of the most expensive item RM "<<maxprice;
    
    

 return 0; 
 }