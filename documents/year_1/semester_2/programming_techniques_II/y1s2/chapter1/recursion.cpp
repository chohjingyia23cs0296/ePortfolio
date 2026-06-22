#include <iostream>
using namespace std;

int sumNumbers(int m,int n){
    int sum=0;
    for(int i=m;i<=n;i++)
        sum+=i;
    return sum;
}
int recursiveSumNumbers(int m,int n){
    if(m==n)
        return m;
    return m+recursiveSumNumbers(m+1,n);
}

int main(){
    cout<<"Sum1: "<<sumNumbers(1,5)<<endl;
    cout<<"Sum2: "<<recursiveSumNumbers(1,5)<<endl;
    cin.get();
    return 0;
}