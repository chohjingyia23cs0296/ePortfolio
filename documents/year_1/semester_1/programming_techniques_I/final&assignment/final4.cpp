#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;
const int NUM_STATE = 14;
const int NUM_YEAR = 10 ;
ofstream out("outputfinal4.txt");
struct dataAcc
{
int numAcc[10]; //number of road accidents from 2006-2015
string state; //states in Malaysia
float avg; //average number of road accidents for 2006-2015
};
double cal_Avg(dataAcc &a);
void find_HighLow(dataAcc data[]);
void displayLine();
int main (){

    dataAcc states[NUM_STATE];
    ifstream infile("inputfinal4.txt");
    if(!infile){
        cout<<"Error\n";
    }
    for(int i=0;i<NUM_STATE;i++){
        for(int j=0;j<NUM_YEAR;j++){
            infile>>states[i].numAcc[j];
        }
        getline(infile,states[i].state);
        states[i].avg=cal_Avg(states[i]);
    }
    infile.close();

    displayLine();
    out<<setw(10)<<"STATE";
    for(int i=2006;i<=2015;i++){
        out<<setw(14)<<i;
    }
    out<<setw(11)<<"AVERAGE\n";

    displayLine();
    for(int i=0;i<NUM_STATE;i++){
        out<<"\n"<<left<<setw(20)<<states[i].state;
        for(int j=0;j<NUM_YEAR;j++){
            out<<setw(11)<<states[i].numAcc[j];
        }
        out<<cal_Avg(states[i]);
    }
    out<<"\n";
    displayLine();
    find_HighLow(states);
    displayLine();

    out.close();

    return 0;

}
double cal_Avg(dataAcc& a){
    int sum=0;
    for(int i=0;i<NUM_YEAR;i++){
        sum +=a.numAcc[i];
    }
    a.avg=static_cast<float>(sum)/NUM_YEAR;
    return a.avg;
    
}
void find_HighLow(dataAcc data[]){
    int highest=-1;
    int highestyear=0;
    int higheststate=0;
    for(int i=0;i<NUM_STATE;i++){
        for(int j=0;j<NUM_YEAR;j++){
            if(data[i].numAcc[j]>highest){
                highest=data[i].numAcc[j];
                higheststate=i;
                highestyear=j;
            }
        }
    }
    
    out << "The highest number of road accidents = " << highest
    << " at" << data[higheststate].state << " in the year " << (2006 + highestyear) << endl;

    
}
void displayLine(){
    for (int i = 0; i < 98; i++){
    out << "-";
    }
    out << endl;
}


