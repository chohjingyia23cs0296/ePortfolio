#include <iostream>
using namespace std;
float calcAverage(int total_movie1,int total_movie2,int totalmovie3);
float calcPrice(float total_rate);
void getInput(int &movie1,int &movie2,int &movie3);
void dispRentalSummary(float overall_total_rate, int total_movie1,int total_movie2,int total_movie3);
int main(){
	char choice;
		string name;
		int movie1=0,movie2=0,movie3=0;
		int total_movie1=0,total_movie2=0,total_movie3=0;
		float total_rate=0,overall_total_rate=0;
		int total_movie=0;
		
	do{
		
		cout<<"<<<<<<<<<<<DATA>>>>>>>>>"<<endl;
		cout<<"Renter Name : ";
		cin.ignore();
		getline(cin,name);
		getInput(movie1,movie2,movie3);
		cout<<"\n";
		total_movie1+=movie1;
		total_movie2+=movie2;
		total_movie3+=movie3;
		
		cout<<"<<<<<<<<<<SUMMARY>>>>>>>>"<<endl;
		total_rate=(movie1*2)+(movie2*5)+(movie3*3.5);
		cout<<"Total Rate (RM): "<<total_rate<<endl;
		cout<<"Final Price(RM): "<<calcPrice(total_rate)<<endl;
		cout<<"\n";
		overall_total_rate+=total_rate;
		cout<<"Press [N] to stop...";
		cin>>choice;
		cout<<"\n";
		
	}while(choice!='N'&&choice!='n');
	total_movie=total_movie1+total_movie2+total_movie3;
	dispRentalSummary( overall_total_rate,  total_movie1, total_movie2, total_movie3);
	
	return 0;
}
float calcAverage(int total_movie1,int total_movie2,int total_movie3){
	return static_cast<float>(total_movie1+total_movie2+total_movie3)/3;
}
float calcPrice(float total_rate){
	float discount;
	if(total_rate<35){
		discount=0.1;
	}else if(total_rate>35&&total_rate<60){
		discount=0.15;
	}else if(total_rate>60){
		discount=0.25;
	}
	return total_rate*(1-discount);
	
}
void getInput(int &movie1,int &movie2,int &movie3){
	cout<<"Movie type 1: ";
	cin>>movie1;
	cout<<"Movie type 2: ";
	cin>>movie2;
	cout<<"Movie type 3: ";
	cin>>movie3;
}
void dispRentalSummary(float overall_total_rate, int total_movie1,int total_movie2,int total_movie3){
	int highest=0;
	string highesttype;
	cout<<"<<<<<<<<<<RENTAL SUMMARY>>>>>>>>>>"<<endl;
	cout<<"Overall Total Rate(RM)             : "<<overall_total_rate<<endl;
	cout<<"Average for 3 types of rentad movie: "<<calcAverage( total_movie1, total_movie2, total_movie3)<<endl;
	if(highest<total_movie1){
		highest=total_movie1;
		highesttype=" Movie Type 1 ";
	}else if(highest<total_movie2){
		highest=total_movie2;
		highesttype=" Movie Type 2 ";
	}else if(highest<total_movie3){
		highest=total_movie3;
		highesttype=" Movie Type 3 ";
	}
	cout<<"Highest type of movie rented       : "<<highesttype<<"("<<highest<<")"<<endl;
}