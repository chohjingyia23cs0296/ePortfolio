#include<iostream>
#include "question3.h"
using namespace std;

Counter::Counter(int maxVal):count(10),maxValue(maxVal){};
void Counter::increment(){
    if(count<maxValue){
        count++;
    }else{
        cout<<"Maximum reach"<<endl;
    }
}
void Counter::decrement(){
    if(count>0){
        count--;
    }else{
        cout<<"minimum reach"<<endl;
    }
}
void Counter::setCount(int value){
    if(value>=0&&value<=maxValue){
        count=value;
    }else{
        cout<<"Counter value should between 0-10"<<endl;
    }
}
void Counter::setMaxVal(int maxVal){
    if(maxVal>0){
        maxValue=maxVal;
    }else{
        cout<<"set maximum value should larger than 0";
    }
}
int Counter::getCount(){
    return count;
}
int Counter::getMaxValue(){
    return maxValue;
}