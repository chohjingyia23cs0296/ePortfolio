#include<iostream>
using namespace std;
const int ROWS=4;
const int COLS=3;
void readNumberMedal(int [][COLS], int);

int readCountry3Total(int [][COLS], int);
int largestnum(int collections[][COLS],int ROWS );
int smallestnum(int collections[][COLS],int ROWS);
int highestnumgold(int collections[ROWS][COLS]);
int totalthirdcolumn(int collections[ROWS][COLS]);
int main(){
    int collections[ROWS][COLS];
    int country3,largest,smallest,highestgold,totalbronze;
    cout<<"Please arrange the medal with gold,silver,bronze"<<endl;
    readNumberMedal(collections, ROWS);
    country3=readCountry3Total(collections, ROWS);
    cout<<"Total number of medals won by country 3: "<<country3<<endl;

    largest=largestnum( collections, ROWS);
    cout<<"Largest number among four country:"<<largest<<endl;

    smallest=smallestnum(collections, ROWS);
    cout<<"Smallest number among four country:"<<smallest<<endl;

    highestgold= highestnumgold( collections);
    cout<<"Largest number among four country in gold medal: "<<highestgold<<endl;

    totalbronze=totalthirdcolumn( collections);
    cout<<"Total number of bronze medals: "<<totalbronze<<endl;

    return 0;
}
void readNumberMedal (int collections[][COLS],int ROWS){
    for (int i=0;i<ROWS;i++){
        for (int j=0; j<COLS;j++){
            cout<<"Country "<<(i+1)<<" medal :";
            cin>>collections[i][j];
    }
    }
}
int readCountry3Total (int collections[][COLS],int ROWS){
    int total=0;
    total=collections[2][0]+collections[2][1]+collections[2][2];
    return total;

}
//Return the largest number of medals won. 
int largestnum(int collections[][COLS],int ROWS ){
    int largest=collections[0][0];
    for (int i=0;i<ROWS;i++){
        for (int j=0; j<COLS;j++){
            if(largest<collections[i][j]){
                largest=collections[i][j];
            }  
    }
    }
    return largest;
}
//Return the smallest number of medals won. 
int smallestnum(int collections[][COLS],int ROWS){
    int smallest=collections[0][0];
    for (int i=0;i<ROWS;i++){
        for (int j=0; j<COLS;j++){
            if(smallest>collections[i][j]){
                smallest=collections[i][j];
            }  
    }
    }
    return smallest;
}
//Return the highest number of gold medal won. 
int highestnumgold(int collections[ROWS][COLS]){
    int highestgold=collections[0][0];
    for(int rows=0;rows<4;rows++){
        for(int col=0;col<1;col++){
            if(highestgold<collections[rows][col]){
                highestgold=collections[rows][col];
            }
        }
    }
    return highestgold;
}
int totalthirdcolumn(int collections[ROWS][COLS]){
    int total=0;
    for(int row=0;row<4;row++){
        total+=collections[row][2];
    }
    return total;
}
