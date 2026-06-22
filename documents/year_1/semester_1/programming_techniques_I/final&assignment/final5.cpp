#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
ofstream out("outputfinal5.txt");
void displayLine();
int findIndWinner(int total[12]);
int findTeamWinner(int sum[3]);
int main(){
    int marks[12][7];
    int total[12];
    int sum[]={0,0,0};
    ifstream infile("inputfinal5.txt");
    if(!infile){
        cout<<"Sorry,input file does not exist!\n";
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<7;j++){
            infile >> marks[i][j];
        }
    }
    infile.close();
    for(int i=0;i<12;i++){
        total[i]=0;
    }

    for(int i=0;i<12;i++){
        for(int j=2;j<7;j++){
            total[i]+=marks[i][j];
        }
    }
    for(int i=0;i<12;i++){
         switch (marks[i][0]){
    case 1:sum[0]+=total[i];
            break;
    case 2:sum[1]+=total[i];
            break;
    case 3:sum[2]+=total[i];
            break;
         }
    }
   
    displayLine();
    out<<"Id\t\tE1\tE2\tE3\tE4\tE5\tTotal\n";
    displayLine();
    
    for(int i=0;i<12;i++){
        if(i%4==0){
            out<<"TEAM "<<marks[i][0]<<"\n";
        }
        for(int j=1;j<7;j++){
            out<<marks[i][j]<<"\t";
        }
        out<<total[i]<<"\n";
        if((i+1)%4==0){
            out<<"TOTAL";
            out<<"\t\t\t\t\t\t"<<sum[marks[i][0]-1]<<"\n";
            displayLine();
        }

    }
    int index=findIndWinner( total);
    int teamindex=findTeamWinner(sum);

    out<<"Winner for Individual Category: "<<marks[index][1]<<"  (Team "<<marks[index][0]<<")\n";
    out<<"Winner for Group Category: Team "<<teamindex+1<<"   (Score = "<<sum[teamindex]<<")\n";

    return 0;
}
void displayLine(){
    for(int i=0;i<52;i++){
        out<<'-';
    }out<<endl;
}
int findIndWinner(int total[12]){
    int winner=total[0];
    int index=0;
    for(int i=0;i<12;i++){
        if(total[i]>winner){
            winner=total[i];
            index=i;
        }
    }
    return index;
}
int findTeamWinner(int sum[3]){
    int teamwinner=sum[0];
    int teamindex=0;
    for(int i=1;i<=3;i++){
        if(sum[i]>teamwinner){
            teamwinner=sum[i];
            teamindex=i;
        }
    }
    return teamindex;
}   