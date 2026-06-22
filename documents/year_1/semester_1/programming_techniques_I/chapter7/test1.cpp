#include<iostream>
using namespace std;
double total_mark(double *mark,int size);
int main(){

    int size;
    double *mark;
    
     cout<<"Enter the number of subject you took this semester : ";
    cin>>size;
    mark=new double[size];
    for(int i=0;i<size;i++){
        cout<<"Enter subject mark"<<(i+1)<<": ";
        cin>>mark[i];
    }
    double total1=total_mark(mark, size);
     cout<<"Total mark:"<<total1;
    delete []mark;

    mark=nullptr;
    return 0;
}

double total_mark(double *mark,int size){
   double total;
    for(int i=0;i<size;i++){
       total+=mark[i];
    }
    return total;

}