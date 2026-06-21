#include<iostream>
using namespace std;
int main(){
    int w[5] = {2, 4, 6, 8, 3};
int *ptr_1 = NULL;
int *ptr_2 = NULL;
int *ptr_3 = NULL;
ptr_3 = &w[0];
ptr_1 = ptr_2=ptr_3 + 2;
cout<<*ptr_1;

      
      int a[4]={0,1,2,3};

      int *first_ptr=NULL;
      int *last_ptr=NULL;
    first_ptr=&a[0];
    last_ptr=first_ptr+3;
    cout<<last_ptr;
	
	return 0 ;
}
    
  