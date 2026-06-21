#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double total=0;
    const int rows=3,col=4;
    double sales[rows][col];
    cout<<"This program will calculate the total sales of all company's division."<<endl;
    cout<<"Enter the following sales data:\n\n";

    for( int i=0;i<rows;i++){
        for( int j=0;j<col;j++){
            cout<<"Division "<<(i+1)<<","<<"Quarter "<<(j+1)<<": $";
            cin>>sales[rows][col];
        }
        cout<<"\n";
    }
    for( int i=0;i<rows;i++){
        for( int j=0;j<col;j++){
            total+=sales[rows][col];
        }
    }
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The total sales for the company are: $"<<total;

    return 0;
}
