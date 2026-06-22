#include<iostream>
using namespace std;
int main(){
    const int rows=3;
    const int col=5;
    int total[rows]={0};
    double average;
    double scores[rows][col]={{88,97,79,86,94},{86,91,78,79,84},{82,73,77,82,89}};

    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            total[i]+=scores[i][j];
        }cout<<"Total number for "<<(i+1)<<":" <<total[i]<<endl;
    }
    average=0.0;
    for(int i=0;i<rows;i++){

            average+=static_cast<double>(total[i]);

    }
    average/=(rows*col);
    cout<<"Average: "<<average<<endl;

    return 0;
}