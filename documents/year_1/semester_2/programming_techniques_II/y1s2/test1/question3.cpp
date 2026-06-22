#include<iostream>
using namespace std;
#include "question3.h"
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
            cout<<"Minimum reach"<<endl;
        }
    }
    void Counter::setCount(int value){
        if(value>=0&&value<=maxValue){
            count=value;
        }else{
            cout<<"Counter value should between 0-10 "<<endl;
        }
    }
        
    
    void Counter::setMaxVal(int maxVal){
        if(maxVal>0){
            maxValue=maxVal;
        }else{
            cout<<"Set maximum value should be greater than 0"<<endl;
        }
    }
    int Counter::getCount(){
        return count;
    }
    int Counter::getMaxVal(){
        return maxValue;
    }