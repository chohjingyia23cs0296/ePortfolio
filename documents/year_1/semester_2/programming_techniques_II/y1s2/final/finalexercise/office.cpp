#include<iostream>
using namespace std;
class Officer{
    private:
    string name;
    int id;
    public:
    Officer(string n,int ID):name(n),id(ID){};
    void set(string n,int ID){
        name=n;
        id=ID;
    }
    void print(){
        cout<<"Officer : "<<name<<" "<<id<<endl;
    }
};
class Offender{
    private:
    string name;
    string ic;
    string address;
    public:
    Offender(string n,string _ic,string add):name(n),ic(_ic),address(add){};
    void set(string n,string _ic,string add){
        name=n;
        ic=_ic;
        address=add;
    }
    void print(){
        cout<<"Offender: "<<name<<" "<<ic<<" "<<address<<endl;
    }
};
class Summon{
    private:
    int code;
    Officer*officer;
    Offender offender;
    public:
    Summon(int c,Officer*o,Offender off):code(c),officer(o),offender(off){};
    void addOfficer(string n,int _id){
        officer->set(n,_id);
    }
    void removeOfficer(){
        delete officer;
    }
    void print(){
        officer->print();
        offender.print();
        cout<<"\n";
        cout<<"Summon code: "<<code<<endl;
        
    }
};
int main(){
    Offender offender("SELAMAT","992112015311","NO! JALAN PS 13 TAMAN");
    Officer *office=new Officer("ALI",7581);
    Summon summon(12,office,offender);
    summon.print();
    summon.addOfficer("AHMAD",87611);
    summon.print();
    return 0;

}