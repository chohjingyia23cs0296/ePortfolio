#ifndef INVENTORYITEM1_H
#define INVENTORYITEM1_H

#include<cstring>

const int DEFAULT_SIZE=100;
class InventoryItem1{
    private:
    char *description;
    double costs;
    int units;

    public:
    InventoryItem1(){
        description=new char[DEFAULT_SIZE];
        *description='\0';
        costs=0.0;
        units=0;
    }
 
    public:
    InventoryItem1 (char*desc){
    description=new char[strlen(desc)+1];
    strcpy(description,desc);
    costs=0.0;
    units=0;
    }

    public:
    InventoryItem1(char*desc,double c,int u){
        description=new char[strlen(desc)+1];
        strcpy(description,desc);
        costs=c;
        units=u;

    }
};

#endif