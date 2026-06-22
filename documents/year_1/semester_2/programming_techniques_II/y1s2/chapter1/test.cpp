#include <iostream>
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
typedef void(*func)(int);
void doCalculation(const int list[],int size,func each){
    for(int i=0;i<5;i++){
        each(list[i]);
    }
    

}
int main(){
    int list[size]={1,4,6,7,3};
    doCalculation(list,size,printOdd);



    return 0;
}