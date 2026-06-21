#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


const int ROW=5;
const int COL=12;
void readFile(int sales[][COL],int ROW,string store[]);
float grandTotalSales(int sales[][COL],int ROW);
float averageMonthySales(int sales[][COL],int ROW);
float monthTotalSales(int sales[][COL],int ROW,int indexcol);
float storeTotalSales(int sales[][COL],int ROW,int indexrow);
void indicesOfHighestSales(int sales[][COL],int ROW,int&storeindex,int&monthindex);

ofstream out("outputfinal3.txt");
int main(){
     int sales[ROW][COL];
    string store[ROW];
    int indexcol=0,indexrow=0;
    int storeindex=0, monthindex=0;
    readFile(sales,ROW,store);

    out<<"Grand total of sales over all stores:RM  "<<right<<setw(10)<<fixed<<setprecision(2)<<grandTotalSales( sales, ROW)<<endl;
    out<<"Average sales per month:             RM  "<<right<<setw(10)<<fixed<<setprecision(2)<<averageMonthySales( sales, ROW)<<endl<<endl;
    
    out<<"The higest sales:\n";
    out<<"----------------\n";
    indicesOfHighestSales( sales, ROW,storeindex,monthindex);
    out<<"Store: "<<store[storeindex]<<"\n";
    out<<"Month: ";
    switch (monthindex) {
        case 0: out << "Jan"; break;
        case 1: out << "Feb"; break;
        case 2: out << "Mar"; break;
        case 3: out << "Apr"; break;
        case 4: out << "May"; break;
        case 5: out << "Jun"; break;
        case 6: out << "Jul"; break;
        case 7: out << "Aug"; break;
        case 8: out << "Sep"; break;
        case 9: out << "Oct"; break;
        case 10: out << "Nov"; break;
        case 11: out << "Dec"; break;
    }
    out<<"\nSales: RM"<<right<<setw(10)<<fixed<<setprecision(2)<<sales[storeindex][monthindex]<<"\n\n";
    
    out<<"Total sales by month:\n";
    out<<"Month\tSales\n";
    out<<"-----\t-----\n";
    for(int indexcol=0;indexcol<COL;indexcol++){
        switch (indexcol) {
        case 0: out << "Jan"; break;
        case 1: out << "Feb"; break;
        case 2: out << "Mar"; break;
        case 3: out << "Apr"; break;
        case 4: out << "May"; break;
        case 5: out << "Jun"; break;
        case 6: out << "Jul"; break;
        case 7: out << "Aug"; break;
        case 8: out << "Sep"; break;
        case 9: out << "Oct"; break;
        case 10: out << "Nov"; break;
        case 11: out << "Dec"; break;
    }
        out<<"\t"<<"   RM"<<right<<setw(10)<<fixed<<setprecision(2)<<monthTotalSales( sales,ROW, indexcol)<<"\n";
    }
    
    
    out<<"\n";

    out<<"Total sales by store:\n";
    out<<"Store\t\tTotal Sales\n";
    out<<"-----\t\t-----------\n";
    
    for(int indexrow=0;indexrow<ROW;indexrow++){
        out<<store[indexrow]<<"   RM"<<right<<setw(10)<<fixed<<setprecision(2)<<storeTotalSales( sales, ROW, indexrow)<<endl;
    }

    out<<"\n";

    out<<"Profitable Stores:\n";
    out<<"-----------------\n";

    for(int i=0;i<ROW;i++){
        float sumstore=storeTotalSales( sales, ROW, i);
        if(sumstore>600000){
            out<<store[i]<<endl;
        }
    }

    out.close();
    return 0;
}
void readFile(int sales[][COL],int ROW,string store[ ]){
    ifstream infile;
    infile.open("inputfinal3.txt");
    if(!infile.is_open()){
        cout<<"Error !";
    }
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            infile>>sales[i][j];
        }
        getline(infile,store[i]);
    }
    infile.close();
}

float grandTotalSales(int sales[][COL],int ROW){
    float sum=0.0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            sum+=sales[i][j];
        }
    }
    return sum*1000;
}
float averageMonthySales(int sales[][COL],int ROW){
    float total=grandTotalSales( sales, ROW);
    return total/COL;
}

float monthTotalSales(int sales[][COL],int ROW,int indexcol){

    float summonth=0.0;
    for(int i=0;i<ROW;i++){
        summonth+=sales[i][indexcol];
    }
    
    return summonth*1000;
}
float storeTotalSales(int sales[][COL],int ROW,int indexrow){

    float sumstore=0.0;
    for(int i=0;i<COL;i++){
        sumstore+=sales[indexrow][i];
    }
    return sumstore*1000;
}
void indicesOfHighestSales(int sales[][COL],int ROW,int&storeindex,int&monthindex){
     storeindex=0;
     monthindex=0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(sales[i][j]>sales[storeindex][monthindex]){
                storeindex=i;
                monthindex=j;
            }
        }
    }
}
