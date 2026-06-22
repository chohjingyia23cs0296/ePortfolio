#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
class Person{
    private:
    string name;
    string NRIC;
    double height;
    double weight;
    double BMI;
    double weight_status;
    public:

    Person(string n=" ",double h=0.0,double w=0){
        name=n;
        height=h;
        weight=w;
        NRIC=" ";
        height=h;
        weight=w;
    }
    string getName() const{
        return name;
    }
    string getStatus()const{
        if(BMI<18.5)
        return "Underweight";
        else if(BMI>=18.5&&BMI<25)
        return "Normal";
        else if(BMI>=25&&BMI<30)
        return "Overweight";
        else if(BMI>=30)
        return "Obese ";
    }
    string getRisk()const{
        if(BMI<18.5)
        return "Risk of nutritional deficiency diseases and osteoporosis";
        else if(BMI>=18.5&&BMI<23)
        return "Low risk";
        else if(BMI>=23&&BMI<27.5)
        return "Moderate risk";
        else if(BMI>=27.5)
        return "High risk ";
    }
    void calcBMI(){
        BMI=weight/pow(height,2);
    }
    
    void readInput(){
        cout<<"Name: ";
        getline(cin,name);
        cout<<"NRIC Number (without hyphen'-'): ";
        getline(cin,NRIC);
        cout<<"Height (in meter): ";
        cin>>height;
        cout<<"Weight (in kg): ";
        cin>>weight;
        cin.ignore();
        calcBMI();
        
    }
    bool operator==(const Person&obj){
        return getStatus()==obj.getStatus();
    }
    void dispInfo(){
        int age;
        int birthYear;
        string gender;
        string str=NRIC.substr(0,2);
        string str1=NRIC.substr(11,1);
        if(stoi(str)>=25){
            birthYear=1900+stoi(str);
        }else{
            birthYear=2000+stoi(str);
        }
        age=2024-birthYear;
        if(stoi(str1)%2==1){
            gender="man";
        }else{
            gender="woman";
        }
        cout<<"Hello, "<<getName()<<endl;
        cout<<"Your are "<<age<<" years old "<<gender<<endl;
    }
    friend ostream &operator<<(ostream &os,const Person&obj);
    
};

ostream &operator<<(ostream &os,const Person&obj){
        os<<"Your height is "<<obj.height<<" meter\n";
        os<<"Your weight is "<<obj.weight<<" kg\n";
        os<<"Your BMI is "<<obj.BMI<<endl;
        os<<"Your weight status is "<<obj.getStatus()<<endl;
        os<<"You have "<<obj.getRisk()<<endl;
        return os;
}

int main(){
    Person p1(" ",0.0,0);
    Person p2("Anis Hashim",1.5,50);
    cout<<"<<< Input >>>\n";
    p1.readInput(); 
    cout<<"\n<<< Output >>>\n";
    p1.dispInfo();
    cout<<fixed<<setprecision(2);
    cout<<p1<<endl;

    
    if(p1==p2){
        cout<<"\n**Note: "<<p1.getName()<<" and "<<p2.getName()<<" have same weight status.\n";
    }else{
        cout<<"\n**Note: "<<p1.getName()<<" and "<<p2.getName()<<" have different weight status.\n";
    }
    return 0;

}
