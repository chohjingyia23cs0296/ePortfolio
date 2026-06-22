#include<iostream>
#include "question3.h"
#include "question3.cpp"
using namespace std;

int main(){
    Counter counter(10);
    cout<<"Initial count value: "<<counter.getCount()<<endl;
    counter.increment();
    counter.increment();
    counter.increment();
    cout<<"Current count value: "<<counter.getCount()<<endl;
    counter.decrement();
    counter.decrement();
    counter.decrement();
    cout<<"Final count value: "<<counter.getCount()<<endl;
    counter.setMaxVal(5);

    counter.increment();
    counter.increment();
    counter.increment();
    cout<<"Current count value: "<<counter.getCount()<<endl;
    return 0;
}
