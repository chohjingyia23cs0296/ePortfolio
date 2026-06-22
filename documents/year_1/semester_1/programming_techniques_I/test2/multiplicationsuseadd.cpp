#include<iostream>
using namespace std;

const int MAX_OPERATIONS=100;
int operands1[MAX_OPERATIONS] ;
int results[MAX_OPERATIONS] ;
int multiplyUsingAddition(int a,int b);
void performMultiplication(int &operationCount);
void displayResult(int &operationCount);
void displayMainMenu(int &operationCount,int&choice);
int main(){
    int choice;
    int operationCount=0;
    while(choice!=3){
        displayMainMenu(operationCount,choice);
        
    }

    return 0;
}
void displayMainMenu(int &operationCount,int &choice){
    
     cout<<"<<<<<<<< Main Menu >>>>>>>>>"<<endl;
    cout<<"========================================"<<endl;
    cout<<"1. Perform Multiplication"<<endl;
    cout<<"2. Display results"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:performMultiplication(operationCount);
        operationCount++;
        break;
        case 2:displayResult( operationCount);
        break;
        case 3:cout << "Goodbye!" << endl;
        cout << "\n\n";
        cout << "---------------------------" << endl;
        break;
        default:cout<<"Invalid input.Please try again."<<endl;
    
    }
}

void performMultiplication(int &operationCount) {
    int operands_count;
    cout << "Enter the number of operands for multiplication: ";
    cin >> operands_count;

    int operands[operands_count];
    for (int i = 0; i < operands_count; i++) {
        cout << "Enter operand " << i + 1 << ": ";
        cin >> operands[i];
    }

    int result = operands[0];
    for (int i = 1; i < operands_count; i++) {
        result = multiplyUsingAddition(result, operands[i]);
    }
    operands1[operationCount] = operands_count;
    results[operationCount] = result;

    cout << "Multiplication performed successfully!" << endl;
}
void displayResult(int &operationCount){
    cout<<"Results of Mathematical Operations: "<<endl;
    cout<<"========================================"<<endl;
    for(int i=0;i<operationCount;++i){
        cout<<"Operation "<<(i+1)<<": "<<results[i]<<"(Operands: "<<operands1[i]<<")\n";
    }
    cout<<"\n\n\n";

}
int multiplyUsingAddition(int a,int b){
    int result = 0;
    if(a==0||b==0){
        return 0;
    }
    for (int i = 0; i < b; ++i) {
        result += a;
    }
    return result;
}