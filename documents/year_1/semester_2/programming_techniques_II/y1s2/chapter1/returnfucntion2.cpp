#include<iostream>
using namespace std;
const int size=5;
void print(int item){
    cout<<item<<endl;
}
void printOdd(int item){
    if(item%2){
        cout<<item<<endl;
    }
}
typedef void (*each)(int);
void forEach(const int list[],int size,each func){
    for(int i=0;i<size;i++){
        func(list[i]);
    }
}

int main(){
   int numbers[size]={1,4,5,3,6};

   forEach(numbers,size,print);
    forEach(numbers,size,printOdd);
  
}


