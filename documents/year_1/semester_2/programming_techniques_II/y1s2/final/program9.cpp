#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    public:
    Person(string n):name(n){};
    void setName(string n){
        name=n;
    }
    string getName(){
        return name;
    }
};
class Doctor:public Person{
    private:
    string department;
    public:
    Doctor(string n,string d):Person(n){
        department=d;
    }
    string getDepartment(){
        return department;
    }
};
class Guardian:public Person{
    private:
    string phone;
    public:
    Guardian(string n,string p):Person(n),phone(p){};
    void setPhone(string p){
        phone=p;
    }
    string getPhone(){
        return phone;
    }
};
class Patient:public Person{
    protected:
    Guardian guardian;
    Doctor*doctor;
    string illness;
    public:
    Patient(string pn,string pi,string gn,string gp):Person(pn),guardian(gn,gp){
        illness=pi;
    }
    void assignDoctor(Doctor*d){
        doctor=d;
        
    }

    virtual void print(){
        cout<<"Patient's Name :"<<getName()<<endl;
        cout<<"Illness: "<<illness<<endl;
        cout<<"Guardian's Name: "<<guardian.getName()<<endl;
        cout<<"Guardian's Phone: "<<guardian.getPhone()<<endl;
        if(doctor){
            cout<<"Doctor's Name "<<doctor->getName()<<endl;
            cout<<"Doctor's Dept. :"<<doctor->getDepartment()<<endl<<endl;
        }else{
            cout<<"*** No doctor assigned yet ***\n\n";
        }
    }
};
class Inpatient:public Patient{
    private:
    string ward;
    public:
    Inpatient(string pn,string pi,string gn,string gp,string pward):Patient(pn,pi,gn,gp){
        ward=pward;
    }
    void print(){
        cout<<"Patient Type: INPATIENT"<<endl;
        cout<<"Ward: "<<ward<<endl<<endl;
        Patient::print();

    }
};
class Outpatient:public Patient{
    private:
    string diagnosis;
    public:
    Outpatient(string pn,string pi,string gn,string gp,string pdiagnosis):Patient(pn,pi,gn,gp){
        diagnosis=pdiagnosis;
    }
    void print(){
        cout<<"Patient Type: OUTPATIENT"<<endl;
        cout<<"Diagnosis: "<<diagnosis<<endl<<endl;
        Patient::print();
    }
};
int main(){
    int choice;
    
    Doctor doctor[2]={Doctor("Dr.Ramli", "ICU"),Doctor("Dr.Kamariah", "Radialogy")};

    Patient *patient[3]={new Outpatient("Rozita","Rozita Sprained","Salleh","4466","X-ray"),
                        new Inpatient("Nurdiana","Respiratory failure ","Jalil","7731","ICU-101"),
                        new Outpatient("Ali","Coronary artery","Bakar","1234","CT-Scan")};
    
    do{
        cout<<"\n========== Menu ==========\n";
    cout<<"1. List Doctors\n";
    cout<<"2. List Patients\n3. Assign Doctor\n4. Exit\n";
    cout<<"Choose an operation [1-4] => ";
    cin>>choice;

        if(choice==1){
        for(int i=0;i<2;i++){
            cout<<"\nDoctor's Name: "<<doctor[i].getName()<<"         Department: "<<doctor[i].getDepartment();
        }
    }else if(choice==2){
        for(int i=0;i<3;i++){
            cout<<"Patient #"<<i+1<<endl;
            patient[i]->print();
        }
    }else if(choice==3){
        int x,y;
        cout<<"Enter the patient index and doctor index => ";
        cin>>x>>y;
        try{
            if(x<0||x>3||y<0||y>3){
                throw "Index is out of range\n";
            }
            patient[x]->assignDoctor(doctor+y);

        }
        catch(const char*e){
            cout<<"** Error: "<<e;
        }
    }else if(choice==4){
        cout<<"End the program\n";
        return 0;
    }else{
        cout<<"Invalid input\n";
    }
    }while(true);
    
}
