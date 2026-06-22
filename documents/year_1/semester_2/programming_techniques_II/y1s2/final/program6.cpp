#include<iostream>
#include<vector>
using namespace std;

class Person{
    protected:
    string name;
    public:
    Person(string n=""):name(n){};
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
    Doctor(string n,string d):Person(n),department(d){};
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
    private:
    string illness;
    Doctor*doctor;
    Guardian guardian;
    public:
    Patient(string pn,string pi,string gn,string gp):Person(pn),illness(pi),guardian(Guardian(gn,gp)),doctor(NULL){};
    
    void assignDoctor(Doctor*d){
        doctor=d;
    }
    virtual void print(){

        cout<<"Patient's Name : "<<name<<endl;
        cout<<"Illness : "<<illness<<endl;
        cout<<"Guardian's Name : "<<guardian.getName()<<endl;
        cout<<"Guardian's Phone : "<<guardian.getPhone()<<endl;

        if (doctor){
            cout << "Doctor's Name  :" << doctor->getName() << endl;
            cout << "Doctor's Dept. :" << doctor->getDepartment() << endl;
        }
        else{
            cout << " ***No doctor assigned yet *** " << endl;
        }
        
    }
};
class OutPatient:public Patient{
    private:
    string diagnosis;
    public:
    OutPatient(string pn,string pi,string gn,string gp,string pdiagnosis):Patient(pn,pi,gn,gp),diagnosis(pdiagnosis){};
    void print()override{
        cout<<"Patient Type: OUTPATIENT"<<endl;
        cout<<"Diagnosis  : "<<diagnosis<<endl;
        Patient::print();
    }
};
class InPatient:public Patient{
    private:
    string ward;
    public:
    InPatient(string pn,string pi,string gn,string gp,string pward):Patient(pn,pi,gn,gp),ward(pward){};
    void print()override{
        cout<<"Patient Type: INPATIENT"<<endl;
        cout<<"Diagnosis  : "<<ward<<endl;
        Patient::print();
    }
};
int main(){
    int choice=0;
    vector<Doctor*>doctor;
    doctor.push_back(new Doctor("Dr.Ramli","ICU"));
    doctor.push_back(new Doctor("Dr.Kamariah","Radiology"));
   
    Patient *patient[3] = {new OutPatient("Rozita", "Sprained ankle", "Salleh", "4466", "X-ray"), 
                                  new InPatient("Nurdiana", "Respiratory failure", "Jalil", "7731", "ICU 101"),
                                  new OutPatient("Ali", "Coronary artery", "Bakar", "1234", "CT Scan")
                                  };
    

    do{
        cout<<"========== Menu ==========\n";
        cout<<"1. List Doctors\n";
        cout<<"2. List Patients\n";
        cout<<"3. Assign Doctor\n";
        cout<<"4. Exit\n";
        cout<<"Choose an operation [1-4] => ";
        cin>>choice;

        switch(choice){
        case 1:
        for(auto doctor:doctor){
            cout<<"Doctor's Name: "<<doctor->getName()<<"      Department : "<< doctor->getDepartment()<<endl;
        }
        break;
        case 2:
        for(int i=0;i<3;i++){
            cout<<"Patient #"<<i+1<<endl;
            patient[i]->print();
            cout<<endl;
        }
        break;
        case 3:
        int pIndex;
        int dIndex;
        cout<<"Enter the patient index and doctor index => ";
        cin>>pIndex>>dIndex;
        try{
            if(pIndex<0||pIndex>3||dIndex<0||dIndex>3){
                throw"Index is our of range\n";
            }
            patient[pIndex]->assignDoctor(doctor[dIndex]);
        }
        catch(const char*error){
            cout<<"** Error: "<<error<<endl;
        }
        break;
        case 4:
        return 0;
            
        default:
            cout<<"Invalid choice\n";

     }
    }while(choice!=4);

}