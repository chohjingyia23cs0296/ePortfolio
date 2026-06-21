#include <iostream>
#include<iomanip>
using namespace std;
void readQty(int&quantityA,int&quantityB,int& quantityC);
void displayHighProd(float totalcommissionA,float totalcommissionB,float totalcommissionC);
float calcAvrg(int numagents,float totalcommission);
void summaryCom(float totalcommissionA,float totalcommissionB,float totalcommissionC,float totalcommission);

int main(){
    string agent;
    int quantityA=0,quantityB=0,quantityC=0;
    float totalcommissionA=0.0, totalcommissionB=0.0, totalcommissionC=0.0, totalcommission=0.0;
    float highestcommission=-1,lowestcommission=99999;
    string highest_commission_name,lowest_commission_name;
    float highestcommissionA=-1,highestcommissionB=-1,highestcommissionC=-1;
    string highest_commission_nameA,highest_commission_nameB,highest_commission_nameC;
    int numagents=0;
    float finaltotalcommission=0.0;
    do{
        cout<<"--------------------AGENT------------------\n";
        cout<<"Agent Name: ";
        getline(cin,agent);
        if(agent.empty()){
            break;
        }
        readQty(quantityA,quantityB, quantityC);
        
        totalcommissionA=quantityA*((150*0.025));
        totalcommissionB=quantityB*((300*0.05));
        totalcommissionC=quantityC*((450*0.1));
        totalcommission=totalcommissionA+totalcommissionB+totalcommissionC;
        summaryCom( totalcommissionA, totalcommissionB, totalcommissionC, totalcommission);
        if(totalcommission>highestcommission){
            highestcommission=totalcommission;
            highest_commission_name=agent;
        }
        if(totalcommission<lowestcommission){
            lowestcommission=totalcommission;
            lowest_commission_name=agent;
        }
        if(totalcommissionA>highestcommissionA){
            highestcommissionA=totalcommissionA;
            highest_commission_nameA=agent;
        }
        if(totalcommissionB>highestcommissionB){
            highestcommissionB=totalcommissionB;
            highest_commission_nameB=agent;
        }
        if(totalcommissionC>highestcommissionC){
            highestcommissionC=totalcommissionC;
            highest_commission_nameC=agent;
        }
        finaltotalcommission+=totalcommission;
        numagents++;
        cin.ignore();
    }while(true);
    cout<<"\n";
    cout<<"------------------SALES ANALYSIS---------------------\n";
    cout<<"Lowest commission for three products: RM "<<lowestcommission<<" ("<<lowest_commission_name<<")"<<endl;
    cout<<"Highest commission for three products: RM "<<highestcommission<<" ("<<highest_commission_name<<")"<<endl;
    cout<<"Highest commission for ProductA: RM "<<highestcommissionA<<" ("<<highest_commission_nameA<<")"<<endl;
    cout<<"Highest commission for ProductB: RM "<<highestcommissionB<<" ("<<highest_commission_nameB<<")"<<endl;
    cout<<"Highest commission for ProductC: RM "<<highestcommissionC<<" ("<<highest_commission_nameC<<")"<<endl;
    cout<<"Total of commission for "<<numagents<<" agents: RM "<<finaltotalcommission<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Average commission for "<<numagents<<" agents:RM "<<calcAvrg( numagents, finaltotalcommission)<<endl;

    return 0;
}
void readQty(int&quantityA,int&quantityB,int& quantityC){

    do{
        cout<<"Product A: ";
        cin>>quantityA;
    }while(quantityA<0||quantityA>100);
    do{
        cout<<"Product B: ";
        cin>>quantityB;
    }while(quantityB<0||quantityB>100);
    do{
        cout<<"Product C: ";
        cin>>quantityC;
    }while(quantityC<0||quantityC>100);

}
void displayHighProd(float totalcommissionA,float totalcommissionB,float totalcommissionC){
    float highest=-1;
    string highesttype;
    string productA,productB,productC;
    if(totalcommissionA>highest){
        highest=totalcommissionA;
        highesttype=productA;
    }
    if(totalcommissionB>highest){
        highest=totalcommissionB;
        highesttype=productB;
    }
    if(totalcommissionC>highest){
        highest=totalcommissionC;
        highesttype=productC;
    }
    cout<<"Highets commission- "<<highesttype<<": RM"<<highest<<endl;
}
float calcAvrg(int numagents,float totalcommission){
    float average=totalcommission/numagents;
    return average;
}
void summaryCom(float totalcommissionA,float totalcommissionB,float totalcommissionC,float totalcommission){
    cout<<"------------------SALES SUMMARY-----------------\n";
    cout<<"Total of commission for three products: RM"<<totalcommission<<endl;
    displayHighProd( totalcommissionA, totalcommissionB, totalcommissionC);
    cout<<"\n";
}