#include <iostream>
#include<cmath>
using namespace std;
int getProblem();
void getRateDropFactor(float&ml,float&drop);
void getKgRateConc(float&mg,float&weight,float&drug);
float figDropsMin(float&ml,float&drop);
float byweight(float&mg,float&weight,float&drug);
int main(){
	float ml=0.0,drop=0.0,weight=0.0,drug=0.0,mg=0.0;
	do{
		int p=getProblem();
		if(p==1){
			getRateDropFactor(ml,drop);
			cout<<"The drop rate per minute is "<<figDropsMin(ml,drop)<<endl;
		}else if(p==2){
			getKgRateConc(mg,weight,drug);
			cout<<"The rate in millilitres per hour is "<< byweight(mg,weight,drug)<<endl;
		}else if(p==3){
			cout<<"You have chosen to quit the program.\n";
					cout<<"Thank you for using our system.\n";
					break;
		}else{
			cout<<"Please run the system again and choose a problem number between 1 and 3\n";
			cout<<"\n";
		}
		cin.ignore();
	}while(true);
	
	return 0;
}
int getProblem(){
	int problem;
	cout<<"INTRAVENOUS RATE ASSISTANT\n\n";
	
	cout<<"Enter the number of the probelm you wish to solve."<<endl;
	cout<<"GIVEN A MEDICAL ORDER IN\t"<<"CALCULATE RATE IN"<<endl;
	cout<<"(1) ml/hr&tubing drop factor\t"<<"drops/min"<<endl;
	cout<<"(2) mg/kg/hr&concentration in mg/ml\t"<<"ml/hr"<<endl;
	cout<<"(3) QUIT\n\n";
	
	cout<<"Problem => ";
	cin>>problem;
	
	return problem;
	
}
void getRateDropFactor(float&ml,float&drop){
	
		cout<<"Enter rate in ml/hr => ";
		cin>>ml;
		cout<<"Enter tubing's drop factor(drops/ml) => ";
		cin>>drop;
	
}
void getKgRateConc(float&mg,float&weight,float&drug){

		cout<<"Enter rate in mg/hr => ";
		cin>>mg;
		cout<<"Enter patient weight in kg => ";
		cin>>weight;
		cout<<"Enter the concentration rate of the drug in mg/ml => ";
		cin>>drug;
}
float figDropsMin(float&ml,float&drop){
	float ratepermin=ml*drop/60;
	ratepermin=static_cast<int>(round(ratepermin));
	return ratepermin;
}
float byweight(float&mg,float&weight,float&drug){
	float mlperhr=mg*weight*drug;
	mlperhr=static_cast<int>(round(mlperhr));
	return mlperhr;
}
