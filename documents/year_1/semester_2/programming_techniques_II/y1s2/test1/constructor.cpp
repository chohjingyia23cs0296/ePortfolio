#include<iostream>
#include<cstring>
using namespace std;

class Inventoryitem{
    private:
    char*description;
    double costs;
    int units;
    public:
    Inventoryitem(char*d,double c,int u){
        description=new char[strlen(d)+1];
        strcpy(description,d);
        costs=c;
        units=u;
    }
     ~Inventoryitem(){
        delete[]description;
    }
    void setCosts(double c){
        costs=c;
    }
    void setUnits(int u){
        units=u;
    }
    const char*getDescription()const{
        return description;
    }
    double getCosts()const{
        return costs;
    }
    int getUnits()const{
        return units;
    }

};
int main(){
    Inventoryitem inventory("Wrench",8.75,20);

    cout<<"Item invenory: "<<inventory.getDescription();
    
    }