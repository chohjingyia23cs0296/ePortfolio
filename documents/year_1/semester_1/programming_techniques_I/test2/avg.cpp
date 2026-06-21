#include <iostream>
#include <cmath>
using namespace std;
void inputNumbers(int num[],int SIZE);
int sum(int num[],int SIZE);
double avrg(int num[],int SIZE);
double f(int num[],int SIZE);
int main(){
	int SIZE;
	int num[SIZE];
	double accumulate;
	for(int j=0;j<2;j++){
		cout<<"List "<<(j+1)<<endl;
		cout<<"How many numbers do you want to enter? => ";
		cin>>SIZE;
		accumulate+=f( num, SIZE);
	}
	cout<<"The value of function f = "<<sqrt(accumulate);
	
	
	
	return 0;
}

void inputNumbers(int num[],int SIZE){
	for(int i=0;i<SIZE;i++){
		cout<<"Enter number "<<(i+1)<<"=>";
		cin>>num[i];
	}
}
int sum(int num[],int SIZE){
	int total=0;
	for(int i=0;i<SIZE;i++){
		total+=num[i];
	}
	return total;
}
double avrg(int num[],int SIZE){
	double avg;
	 avg= static_cast<double>(sum( num, SIZE))/ SIZE;
	return avg;
}
double f(int num[],int SIZE){
	
	double avg;
	inputNumbers(num,SIZE);
	sum(num, SIZE);
	cout<<"\n";
	return avrg(num, SIZE);	
}