#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    string matric;
    double GPA;
    double CGPA;
    int credit;
    int totalcredit;
    string result;

    public:
    Student(string n=" ",string m=" ",double CGPA_=0.0,int tc=0){
        name=m;
        matric=m;
        CGPA=CGPA_;
        GPA=0.0;
        totalcredit=tc;
    }
    string getName()const{
        return name;
    }
    string getStatus()const{
        if(CGPA<1.7)
        return "Fail Status";
        else if(CGPA>=1.7&&CGPA<2.0)
        return "Probation Status";
        else 
        return "Good Status";
        
    }
    void updateCGPA(){
        if(CGPA==0)
        CGPA=(GPA*credit+CGPA*totalcredit)/(credit+totalcredit);
    }
    void readInput(){
        cout<<"Name: ";
        getline(cin,name);
        cout<<"Matric Number: ";
        getline(cin,matric);
        cout<<"CGPA: ";
        cin>>CGPA;
        cout<<"Total Credit: ";
        cin>>totalcredit;
        cout<<"GPA: ";
        cin>>GPA;
        cout<<"Credit earned this semester: ";
        cin>>credit;
        updateCGPA();
    }
    bool operator==(const Student&obj){
        if(getStatus()==obj.getStatus()){
            return true;
        }else{
            return false;
        }
    }
    friend void dispInfo(const Student&obj){
        int year;
        string program;
        string str=obj.matric.substr(1,2);
        if(20-stoi(str)==4)
        year=4;
        if(20-stoi(str)==3)
        year=3;
        if(20-stoi(str)==2)
        year=2;
        if(20-stoi(str)==1)
        year=1;

        string str1=obj.matric.substr(3,2);
        if(str1=="CS")
        program="Computer Science";
        else if(str1=="EC")
        program="Engineering Computing";
        else
        program=="Non Computing Program";
        cout<<"Your are in year "<<year<<" in "<<program<<endl;
    }
     friend ostream& operator<<(ostream&os, Student&obj){
        os<<"Hello, "<<obj.getName()<<endl;
        dispInfo(obj);
        os<<"Your matric number is "<<obj.matric<<endl;
        os<<"Your current CGPA is "<<obj.CGPA<<endl;
        os<<"Your status is "<<obj.getStatus()<<endl;
        if(obj.CGPA>3.67)
        cout<<"CONGRATULATIONS. You are awarded DEANs LIST\n";
        return os;
    }
};
int main(){

    Student p1;
    Student p2("Hashim Abu","A17CS1234",4.0,18);
    cout<<"CGPA Calculator\n\n";
    cout<<"<<< Input >>>\n";
    p1.readInput();
    cout<<"\n<<< Output >>>\n";
    cout<<p1;
    cout<<"\n";
    cout<<p2;
    cout<<endl;
    if(p1==p2)
    cout<<"**Note: "<<p1.getName()<<" and "<<p2.getName()<<" have GOOD status\n";
    else
    cout<<"**Note: "<<p1.getName()<<" and "<<p2.getName()<<" have different status\n";
    return 0;
}