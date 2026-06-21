#include<iostream>
using namespace std;
void changeName(char[][25],int size);
int main(){
    const int STRING_SIZE=25;
    int size=5;
    char name[5][25]={"ali", "abu", "jingyi", "Hi", "ahming"};
    changeName(name,size);
    

    return 0;
}
void changeName(char name[][25],int size){
    
    for(int i=0;i<size;i++){
            cout<<"Name "<<i+1<<":"<<name[i]<<endl;
        
    }
}