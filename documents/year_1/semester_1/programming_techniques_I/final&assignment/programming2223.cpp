#include <iostream>
#include<limits>
using namespace std;

void readQty(int &quantityA,int &quantityB,int &quantityC);
void displayHighProd(int &quantityA,int &quantityB,int &quantityC,double &highestcomission,double &commissionA,double &commissionB,double &commissionC);
void summaryCom(int&quantityA,int &quantityB,int &quantityC,double &commissionA,double &commissionB,double &commissionC,double&totalcommission);
 
double calcAvrg(double &avg,double&finaltotalcommission,int &numagent){
    avg=finaltotalcommission/numagent;
    return avg;
}
int main(){
    string agent,lowestagent,highestagent,highestcomAagent,highestcomBagent,highestcomCagent;
    int numagent=0;
    int quantityA, quantityB, quantityC;
    double totalcommission,highestcommission, commissionA, commissionB, commissionC,highestcomB,highestcomA,highestcomC;
    double finaltotalcommission,avg; 
    double lowest = numeric_limits<double>::max();
    double highest = numeric_limits<double>::min();
    do{
    cout<<"-----------------------------Agent-----------------------------"<<endl;
    cout<<"Agent Name: ";
    getline(cin,agent);   
    if(agent.empty()){
        break;
    }
    readQty(quantityA, quantityB, quantityC);
    summaryCom(quantityA, quantityB, quantityC, commissionA, commissionB, commissionC, totalcommission);

    if(totalcommission<lowest){
            lowest=totalcommission;
            lowestagent=agent;
        }
    if(totalcommission>highest){
            highest=totalcommission;
            highestagent=agent;
        }
    if(commissionA>highestcomA){
        highestcomA=commissionA;
        highestcomAagent=agent;
    }
    if(commissionB>highestcomB){
        highestcomB=commissionB;
        highestcomBagent=agent;
    }
    if(commissionC>highestcomC){
        highestcomC=commissionC;
        highestcomCagent=agent;
    }

    numagent++;
    finaltotalcommission+=totalcommission;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(true);
    cout<<"-----------------------------SALES ANALYSIS-----------------------------"<<endl;
    
    cout<<"Lowest commision for three products: RM "<<lowest<<" "<<"("<<lowestagent<<")"<<endl;
    cout<<"Highest commision for three products: RM "<<highest<<" "<<"("<<highestagent<<")"<<endl;
    cout<<"Highest commission for product A: RM"<<highestcomA<<" "<<"("<<highestcomAagent<<")"<<endl;
    cout<<"Highest commission for product B: RM"<<highestcomB<<" "<<"("<<highestcomBagent<<")"<<endl;
    cout<<"Highest commission for product C: RM"<<highestcomC<<" "<<"("<<highestcomCagent<<")"<<endl;
    cout<<"Total of commission for "<<numagent<<" agents: RM"<<finaltotalcommission<<endl;
    cout<<"Average commission for "<<numagent<<" agents:RM"<<calcAvrg(avg,finaltotalcommission, numagent)<<endl;

    return 0;
}
void readQty(int& quantityA,int &quantityB,int &quantityC){
    cout<<"Product A: ";
    cin>>quantityA;
    while(quantityA<0||quantityA>100){
        cout<<"Product A: ";
    cin>>quantityA;
    }
    cout<<"Product B: ";
    cin>>quantityB;
    while(quantityB<0||quantityB>100){
        cout<<"Product A: ";
    cin>>quantityB;
    }
    cout<<"Product C: ";
    cin>>quantityC;
    while(quantityC<0||quantityC>100){
        cout<<"Product C: ";
    cin>>quantityC;
    }
}
void displayHighProd(int &quantityA,int &quantityB,int &quantityC,double &highestcommission,double &commissionA,double &commissionB,double &commissionC){
    char producttype;
    commissionA=quantityA*((150*0.025));
    commissionB=quantityB*((300*0.05));
    commissionC=quantityC*((450*0.10));
    highestcommission=commissionA;
    producttype='A';
    if(commissionB>highestcommission){
        highestcommission=commissionB;
        producttype='B';
    }
    if(commissionC>highestcommission){
        highestcommission=commissionC;
        producttype='C';
    }
    
    cout<<"Highest commision - Product "<<producttype<<": RM"<<highestcommission;
}
void summaryCom(int &quantityA,int &quantityB,int &quantityC,double &commissionA,double &commissionB,double &commissionC,double&totalcommission){
    double highestcommission;
    commissionA=quantityA*((150*0.025));
    commissionB=quantityB*((300*0.05));
    commissionC=quantityC*((450*0.10));
    totalcommission=commissionA+commissionB+commissionC;
    cout<<"-----------------------------SALES SUMMARY-----------------------------"<<endl;;
    cout<<"Total of commision for three products: RM"<<totalcommission<<endl;;
    displayHighProd(quantityA,quantityB,quantityC,highestcommission,commissionA, commissionB, commissionC);
    cout<<endl;
    cout<<endl;

}

