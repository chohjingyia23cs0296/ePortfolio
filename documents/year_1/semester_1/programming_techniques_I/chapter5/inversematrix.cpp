#include <iostream>
using namespace std;

int main() {
    const int rows=2;
    const int col=3;
    int num[rows][col];
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<"Rows"<<(i+1)<<": "<<"Columns"<<(j+1)<<": ";
            cin>>num[i][j];
        }
    }
    for(int j=col-1;j>=0;j--){
        for(int i=rows-1;i>=0;i--){
            cout<<num[i][j]<<"  ";
        }cout<<endl;
    }

    return 0;
}
