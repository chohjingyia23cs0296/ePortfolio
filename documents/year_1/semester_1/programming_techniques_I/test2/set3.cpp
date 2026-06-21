#include <iostream>
using namespace std;
void dispStatus(int num_active);
void getInput(int &totalcases,int &newcase,int& totaldeath,int &totalrecovered);
float calcAverage(int numstates,int num_active);
void dispOutput(int num_active);
int main(){
	string name,highestname;
		string choice;
		int totalcases,newcase, totaldeath,totalrecovered;
		int num_active;
		int highest=0;
		int finaltotal=0;
		int numstates;
		
	do{
		
		cout<<"<<<<<<<<<<< DATA >>>>>>>>>>>>>>"<<endl;
		cout<<"State name     : ";
		getline(cin,name);
		
		getInput(totalcases,newcase, totaldeath,totalrecovered);
		cout<<endl;
		num_active=totalcases+newcase-totaldeath-totalrecovered;
		dispOutput( num_active);
		cout<<endl;
		if(num_active>highest){
			highest=num_active;
			highestname=name;
		}
		
		finaltotal+=num_active;
		numstates++;
		cin.ignore();
		cout<<"Press <ENTER> to continue...";
		getline(cin,choice);
		if(!choice.empty()){
			break;
		}
	
	}while(true);
	cout<<"<<<<<<<<<<< ACTIVE CASES >>>>>>>>>>>"<<endl;
	cout<<"Total  : "<<finaltotal<<endl;
	cout<<"Highest: "<<highest<<" ("<<highestname<<")"<<endl;
	cout<<"Average for "<<numstates<<" states: "<<calcAverage(numstates,finaltotal)<<endl;
	
	return 0;
}
void dispStatus(int num_active){
	if(num_active>40){
		cout<<"Status:        Red zone"<<endl;
	}else if(num_active>21&&num_active<40){
		cout<<"Status:        Orange zone"<<endl;
	}else if(num_active>1&&num_active<20){
		cout<<"Status:        Yellow zone"<<endl;
	}else if(num_active==0){
		cout<<"Status:        Green zone"<<endl;
	}
}
void getInput(int &totalcases,int &newcase,int& totaldeath,int &totalrecovered){
	cout<<"Total cases    : ";
	cin>>totalcases;
	cout<<"New cases      : ";
	cin>>newcase;
	cout<<"Total death    : ";
	cin>>totaldeath;
	cout<<"Total recovered: ";
	cin>>totalrecovered;
}
float calcAverage(int numstates,int num_active){
	return static_cast<float>(num_active)/numstates;
}
void dispOutput(int num_active){
	cout<<"<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>"<<endl;
	cout<<"Active cases: "<<num_active<<endl;
	dispStatus(num_active);
	cout<<endl;
}