#include <iostream>
#include <cctype>
using namespace std;
void displayMenu();
void countWords();
float calc_Q(int current);
void calcElecRest();
const int SIZE=100;
int main() {
	
	displayMenu();
	return 0;
}
void displayMenu(){
	int choice;
	int power=0;
	float voltage=0.0;

	cout<<"::MIS TERM TEST SYSTEM MENU::"<<endl;
	cout<<"\t"<<"(1)Words count calculator"<<endl;
	cout<<"\t"<<"(2)Electric charges calculator"<<endl;
	cout<<"\t"<<"(3)Quit"<<endl;
	cout<<"\n";
	cout<<"Your choice >> ";
	cin>>choice;
	cin.ignore();
	switch(choice){
		case 1: countWords( );
				break;
		case 2: 
		calcElecRest();
		break;
		case 3: cout<<"Thank you for using our system..."<<endl;
		break;
		default:cout<<"Invalid input."<<endl;
	}
	
}
void countWords(){

	int c=0,i=1;
    bool answer= true;
    char strings[SIZE];
    cout<<"::WORDS COUNT CALCULATOR::"<<endl;
    cout<<endl;
    cout<<"Enter a string: ";
    cin.getline(strings,SIZE);
    cout<<endl;
    cout<<"List of words:"<<endl;
    do{
        cout<<"\tWord "<<i<<" >> ";
        while(strings[c]!=' '){
            if((!ispunct(strings[c]))&&(!isalpha(strings[c]))&&(!isdigit(strings[c]))){
                answer=false;
                break;
            }
            if(isalpha(strings[c])){
                strings[c]= tolower(strings[c]);
                cout<<strings[c];
            }
            c++;
        }
        do{
            c++;
        }while((strings[c]==' ')||(!isalpha(strings[c])));
        cout<<endl;
        i++;
    }while(answer);
    cout<<"\nThe number of words = "<<i-1<<endl;
}
void calcElecRest(){
	int power=0;
	float voltage=0.0;
	int current=0;
	cout<<"Please enter the power (P) in Watts"<<endl<<"and the voltage (V) in kilovolts\n\n";

	do{
		cout<<"Power(W)   = ";
		cin>>power;
		cout<<"Voltage(kV) = ";
		cin>>voltage;
		   
		if(power<=0||voltage<=0){
			cout<<"Invalid input.Please try again !"<<endl;
		}else{
			break;
		}
	}while(true);
	current=power/(voltage*1000);
	float charge=calc_Q(current);
	cout<<"Power,P = "<<power<<" watts"<<endl;
	cout<<"Volatge,V = "<<voltage*1000<<" volts"<<endl;
	cout<<"Electric current, I = "<<current<<" amperes"<<endl;
	cout<<"Electric charge, Q = "<<charge<<" coulombs"<<endl;
	
}
float calc_Q(int current){
	float time=0.0;
	cout<<"Enter the time of current flow, t in minutes = ";
	cin>>time;
	cout<<"\n";
	
	 return current*time*60;
}


