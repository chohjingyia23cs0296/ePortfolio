#include <iostream>
using namespace std;

int average1(int array1[], int size);
double average2(double array2[], int size);
int main(){
    int size=6;
    int array1[size]={1,2,3,4,5,6} ;
    double array2[size]={6.0,4.4,1.9,2.9,3.4,3.5};
   
    double result3=average1(array1, size);
    cout<<result3<<endl;
    double result4=average2(array2, size);
    cout<<result4;
    
    return 0;
}
int average1(int array1[], int size){
    int total=0;
    for (int i=0;i<size;i++){
         total+=array1[i];
    }
    return total/size;
}
double average2(double array2[], int size){
    double total=0.0;
    for (int i=0;i<size;i++){
         total+=array2[i];
    }
    return total/size;
}
/*int grades[30][10];
24
sales[0][0]=56893.12;
cout<<sales[5][3]
int settings[3][5]
2     3     0      0
7     9     2      0
1     0     0      0
void displayArray7(int arr[][7],int rows[]){
    for (int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}
 
int hours[5][7];
               int stamps[8][7];
               int autos[12][7];
               int cats[50][7];
*/