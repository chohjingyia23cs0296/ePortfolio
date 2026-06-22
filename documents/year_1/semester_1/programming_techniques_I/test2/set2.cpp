#include<iostream>
#include<iomanip>
using namespace std;
void getInput(int &question1,int &question2,int &question3);
void dispTier(int totalmark);
float calcAverage(int numstudents,int totalmarks);
void dispSummary(int totalmarks);
int main(){
	string name,highestname,lowestname;
		int question1, question2, question3;
		int totalmarks=0;
		int numstudents=0;
		int finaltotalmark=0;
		float average_score;
		int highest=0,lowest=300;
	do{
		
		cout<<"<<<<<<<<<<<<<DATA>>>>>>>>>>>>>"<<endl;
		cout<<"Name      :";
		getline(cin,name);

	if(name.empty()){
		break;
	}	
	getInput(question1, question2,question3);
	cout<<"\n";
	
	totalmarks = (question1 * 35 / 100) + (question2 * 25 / 100) + (question3 * 40 / 100);

	dispSummary(totalmarks);
	if(totalmarks<lowest){
		lowest=totalmarks;
		lowestname=name;
	}
	if(totalmarks>highest){
		highest=totalmarks;
		highestname=name;
	}
	
	numstudents++;
	finaltotalmark+=totalmarks;
	average_score=calcAverage( numstudents, finaltotalmark);
	cin.ignore();
	}while(true);
	cout<<"<<<<<<<<<<<<<RESULTS ANALYSIS>>>>>>>>>>>>>>>>"<<endl;
	cout<<"Lowest mark : "<<lowest<<" ("<<lowestname<<" )"<<endl;
	cout<<"Highest mark :"<<highest<<" ("<<highestname<<" )"<<endl;
	cout<<"Average for "<<numstudents<<" students: "<<average_score<<endl;
	
	return 0;
}
void getInput(int &question1,int& question2,int &question3){
	cout<<"Q1 mark: ";
	cin>>question1;
	cout<<"Q2 mark: ";
	cin>>question2;
	cout<<"Q3 mark: ";
	cin>>question3;
}
void dispTier(int totalmarks){

	if(totalmarks<40){
		cout<<"Tier       :"<<"Tier 3"<<endl;
	}else if(totalmarks>40&&totalmarks<75){
		cout<<left<<setw(13)<<"Tier       :"<<"Tier 2"<<endl;
	}else if(totalmarks>=75){
		cout<<left<<setw(13)<<"Tier       :"<<"Tier 1"<<endl;
	}
}
float calcAverage(int numstudents,int totalmarks){
	return static_cast<float>(totalmarks)/numstudents;
}
void dispSummary(int totalmarks){
	cout<<"<<<<<<<<<<<<SUMMARY>>>>>>>>>>>>>>>>"<<endl;
	cout<<"Total marks: "<<totalmarks<<endl;
	dispTier(totalmarks);
	cout<<"\n";
}