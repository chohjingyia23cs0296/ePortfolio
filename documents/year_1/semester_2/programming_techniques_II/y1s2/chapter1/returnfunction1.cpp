#include<iostream>
using namespace std;
const int size = 5; // Avoid using a common name like "size" to minimize conflicts

void print(int item){
    cout << item << endl;
}

void printOdd(int item){
    if(item % 2){
        cout << item << endl;
    }
}

void forEach(const int list[], int size, void(*f)(int)){
    for(int i = 0; i < size; i++){
        f(list[i]);
    }
}

int main(){ 
   int numbers[size] = {1, 4, 5, 3, 6};

   forEach(numbers, size, print);
   forEach(numbers, size, printOdd);
  
   return 0;
}

