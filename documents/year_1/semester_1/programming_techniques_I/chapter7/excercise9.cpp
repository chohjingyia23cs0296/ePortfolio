#include<iostream>
#include <ctime>
using namespace std;
int *getRandomNumbers(int num){
    int*array;
    if(num<=0)
    return NULL;
    array=new int[num];
    srand(time(0));
    for(int count=0;count<num;count++)
    array[count]=rand();
    return array;
}
int main(){
    int num;
    getRandomNumbers( num);


    return 0;
}
