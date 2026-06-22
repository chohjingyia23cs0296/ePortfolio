#include<iostream>
using namespace std;
int main(){
    int w[4],*first_ptr=NULL,*last_ptr=NULL;
   first_ptr=&w[0];
   last_ptr=first_ptr+2;
   cout<<*first_ptr;
    
    
   /*
   
   int x[5]={2,4,78,8,3};
    int*ptr_1=NULL,*ptr_2=NULL,*ptr_3=NULL;
    ptr_3=&x[0];//2
    ptr_1=ptr_3+2;//6//see this
    cout<<*ptr_1;//2
   */
    
    return 0;
}