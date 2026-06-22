#include <iostream>
using namespace std;
 class Count{
    public: int num;
    Count(int c){
        num=c;
    }
    Count(){
        num=0;
    }
};

void increment(Count c){
    c.num++;
}
int main(){
    Count myCount;
    for(int i=0;i<10;i++)
    increment(myCount);
    cout<<myCount.num;
    return 0;
}