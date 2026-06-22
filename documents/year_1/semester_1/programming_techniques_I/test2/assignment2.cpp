#include<iostream>
#include <iomanip>
using namespace std;
void model(int &car,string &carModel);
void variant(int &variants,string &variantstype);
void region(int &regions,string &regiontype);
void carInfo(string &carModel,string &variantstype,string &regiontype,double &pricespecific);
void price(double &pricespecific,int &car,int variants,int regions);
int main(){
    //CHOH JING YI
    //LIOW JIA FENG
    int car,variants,regions,period,downpayment;
    double pricespecific,rate,installment,paymentinterest,paymentwithoutinterst;
    string carModel,variantstype,regiontype;
    char choice;

    cout<<"Proton Car Loan Calculator"<<endl;
    cout<<endl;

    do{
    model(car, carModel);
    variant(variants, variantstype);
    region(regions,regiontype);
    cout<<endl;
    price(pricespecific, car, variants, regions);
    carInfo(carModel, variantstype,regiontype,pricespecific);
    cout<<endl;

    cout<<"Down Payment(MYR) : ";
    cin>>downpayment;
    cout<<"Interest rate (%) : ";
    cin>>rate;
    cout<<"Repayment period(in years): ";
    cin>>period;
    rate/=100;
    paymentinterest=(pricespecific-downpayment)*rate*period/(period*12);
    paymentwithoutinterst=(pricespecific-downpayment)/(period*12);
    installment=paymentinterest+paymentwithoutinterst;
    cout<<"MONTHLY INSTALLMENT(MYR): "<<installment<<endl;
    cout<<endl;
    cout<<"Do you want to enter other data? [Y @ N]: ";
    cin>>choice;
    }while(choice!='N'&&choice!='n');

    cout<<endl;
    cout<<"Thank you :)";

    return 0;
}
void model(int &car,string &carModel) {

    cout<<"Model [1-X50, 2-Exora, 3-Persona]: ";
    cin>>car;
    if(car==1){
        carModel="X-50";
    }else if(car==2){
        carModel="Exora";
    }else if(car==3){
        carModel="Persona";
    }else{
        cout<<"Invalid variant selection.";
    }

}
void variant(int &variants,string &variantstype) {

    cout<<"Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
    cin>>variants; 
    if(variants==1){
        variantstype="1.6L Standard CVT";
    }else if(variants==2){
        variantstype="1.6L Premium CVT";
    }else{
        cout<<"Invalid variant selection.";
    }
}
void region(int &regions,string &regiontype) {

    cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
    cin>>regions;
    if(regions==1){
        regiontype="1.6L Standard CVT";
    }else if(regions==2){
        regiontype="1.6L Premium CVT";
    }else{
        regiontype="Invalid region selection.";
    }
}
void price(double &pricespecific,int &car,int variants,int regions){
    if(car==1&&variants==1&&regions==1){
        pricespecific=86300.00;
    }else if(car==1&&variants==2&&regions==1){
        pricespecific=101800.00;
    }else if(car==1&&variants==1&&regions==2){
        pricespecific=88300;
    }else if(car==1&&variants==2&&regions==2){
        pricespecific=103800;
    }else if(car==2&&variants==1&&regions==1){
        pricespecific=62800;
    }else if(car==2&&variants==1&&regions==2){
        pricespecific=62800;
    }else if(car==2&&variants==2&&regions==1){
        pricespecific=69800;
    }else if(car==2&&variants==2&&regions==2){
        pricespecific=69800;
    }else if(car==3&&variants==1&&regions==1){
        pricespecific=47800;
    }else if(car==3&&variants==2&&regions==1){
        pricespecific=53300;
    }else if(car==3&&variants==1&&regions==2){
        pricespecific=49800;
    }else if(car==3&&variants==2&&regions==2){
        pricespecific=55300;
    }
}
void carInfo(string &carModel,string &variantstype,string &regiontype,double &pricespecific){
    cout<<"Car Info"<<endl;
    cout<<"Model:"<<carModel<<endl;
    cout<<"variant: "<<variantstype<<endl;
    cout<<"Region: "<<regiontype<<endl;
    cout<<"Paint Type: Metallic"<<endl;
    cout<<fixed << setprecision(2);
    cout<<"Price (MYR): "<<pricespecific<<endl;
}
