#include <iostream>
using namespace std;

const int NAMES = 5, SIZE = 15;

void changeName(char [][SIZE], int NAMES);
int main()
{
    char students[NAMES][SIZE] = {"Hidayah", "Too", "Fawwaz", "Rao", "Azry"};
    changeName(students,5);
    for(int i=0;i<NAMES;i++){
        cout<<"The "<<i+1<<" name is: "<<students[i]<<endl;
    }
    return 0;   
}
void changeName(char students[][SIZE], int NAMES)
{
    for(int i=0;i<SIZE;i++){ 
         students[0][i]="Maisah"[i];
    }
    for(int i=0;i<SIZE;i++){
        students[2][i]="Nuha"[i];
    }
}