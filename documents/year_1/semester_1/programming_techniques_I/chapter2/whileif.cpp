#include <iostream>
using namespace std;
int main(){
   char id;
   double totalcost=0;
   double cost;
   int quantity;

   do{
    cout<<"Enter the item id: ";
    cin>>id;
    if(id=='A')
    cost=2.0;
    else if(id=='O')
    cost=2.5;
    else if(id=='L')
    cost=1.8;
    else
    break;
    
    cout<<"Enter the quantity of item: ";
    cin>>quantity;
    cout<<endl;
    totalcost+=cost*quantity;
    
   }while(true);
       cout<<"The total price is: RM"<<totalcost<<endl;
   
   return 0;
}