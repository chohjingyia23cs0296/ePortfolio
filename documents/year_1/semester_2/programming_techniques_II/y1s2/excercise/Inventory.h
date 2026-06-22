#ifndef INVENTORY_H
#define INVENTORY_H
#include<cstring>

    class Inventory{
        private:
        char *description;
        int units;
        double costs;

        public:
        Inventory(char*desc,int u,double c){
            description=new char[strlen(desc)+1];
            strcpy(description,desc);
            units=u;
            costs=c;

        }
        
    ~Inventory(){
        delete[]description;
    }
    const char *getDescription()const{
        return description;
    }
    int getUnits()const{
            return units;
        }
        double getCosts()const{
            return costs;
        }
    
    };

#endif