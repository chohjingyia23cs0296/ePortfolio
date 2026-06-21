#include <iostream>
using namespace std;
int arr();
const int SIZE=8;
    int num[SIZE];
int main(){
    //{1, 2, 4, 5, -22, 3, 2, -22};
    int smallestindex;
    cout<<"This program is to find the smallest index in the element."<<endl;
        for(int i=0;i<SIZE;i++){
        cout<<"Please enter num "<<(i+1)<<": ";
        cin>>num[i]; 
    }
    smallestindex=arr();
    cout<<"Smallest index is: "<<smallestindex<<endl;
}
int arr(){
    int smallest=num[0];
    int smallestindex=0;
    for(int i=0;i<SIZE;i++){
     if (smallest>num[i]){
            smallest=num[i];
            smallestindex=i;
        }
    }
    return smallestindex;
}