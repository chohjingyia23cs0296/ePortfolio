#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Employee{
    string name;
    string department;
    float basic_salary;
    float OT;
    float overtimepay;
    float totalsalary;
};
const int MAX_EMPLOYEE=50;
ofstream out("outputfinal1.txt");
int readInput(const string file,Employee employee[]);
void displayOutput(Employee employee[],int numemployee);
float determineRate(string&department);
void displayAnalysis(Employee employee[],int numemployee);
int main(){

    Employee employee[MAX_EMPLOYEE];
    int numemployee=readInput("inputfinal1.txt", employee);
    displayOutput( employee, numemployee);
    displayAnalysis( employee, numemployee);
    return 0;
}
int readInput(const string file,Employee employee[]){
    ifstream infile(file);
    int numemployee=0;
    
    for(int i=0;i<MAX_EMPLOYEE;i++){
        infile>>employee[i].department>>employee[i].basic_salary>>employee[i].OT;
        getline(infile,employee[i].name);
        if(!employee[i].name.empty()){
        numemployee++;
    }
    }
    return numemployee;
}
float determineRate(string&department){
    if(department=="Production")
    return 10.0;
    else if(department=="Quality")
    return 11.5;
    else if(department=="Accounting")
    return 12.5;
    else if(department=="Engineering")
    return 15.0;
}
void displayOutput(Employee employee[],int numemployee){
    
    
    for(int i=0;i<99;i++){
        out<<'-';
    }out<<"\n";
    out<<left;
    out<<setw(20)<<"NAME"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"BASIC(RM)"<<setw(15)<<"OT (HOUR)"
    <<setw(15)<<"OT PAY(RM)"<<setw(15)<<"SALARY (RM)\n";
    for(int i=0;i<99;i++){
        out<<'-';
    }out<<"\n";
    
    for(int i=0;i<numemployee;i++){
        employee[i].overtimepay= determineRate(employee[i].department)*employee[i].OT;
        employee[i].totalsalary=employee[i].overtimepay+employee[i].basic_salary;
    }
    for(int i=0;i<numemployee;i++){
        out<<fixed<<setprecision(2);
        out<<setw(20)<<employee[i].name<<setw(15)<<employee[i].department<<setw(15)<<employee[i].basic_salary<<
        setw(15)<<employee[i].OT<<setw(15)<<employee[i].overtimepay<<setw(15)<<employee[i].totalsalary<<"\n";
    }
    for(int i=0;i<99;i++){
        out<<'-';
    }out<<"\n";
   
}
void displayAnalysis(Employee employee[],int numemployee){
    float totalProduction=0,totalEnginnering=0,totalQuality=0,totalAccounting=0;
    float totalSalaryP=0,totalSalaryE=0,totalSalaryQ=0,totalSalaryA=0;
    
    for(int i=0;i<numemployee;i++){
        if(employee[i].department=="Production"){
            totalProduction+=employee[i].overtimepay;
            totalSalaryP+=employee[i].totalsalary;
        }else if(employee[i].department=="Quality"){
            totalQuality+=employee[i].overtimepay;
            totalSalaryQ+=employee[i].totalsalary;
        }else if(employee[i].department=="Engineering"){
            totalEnginnering+=employee[i].overtimepay;
            totalSalaryE+=employee[i].totalsalary;
        }else if(employee[i].department=="Accounting"){
            totalAccounting+=employee[i].overtimepay;
            totalSalaryA+=employee[i].totalsalary;
        }
        
    }
    out << left << fixed << setprecision(2);
out << setw(25) << "DEPARTMENT" << setw(25) << "TOT. OT PAY" << setw(10) << "TOT. SALARY(RM)\n";
out << setw(25) << "Production" << setw(25) << totalProduction << setw(25) << totalSalaryP << "\n";
out << setw(25) << "Quality" << setw(25) << totalQuality << setw(25) << totalSalaryQ << "\n";
out << setw(25) << "Engineering" << setw(25) << totalEnginnering << setw(25) << totalSalaryE << "\n";
out << setw(25) << "Accounting" << setw(25) << totalAccounting << setw(25) << totalSalaryA << "\n";
for(int i=0;i<99;i++){
        out<<'-';
    }out<<"\n";
}