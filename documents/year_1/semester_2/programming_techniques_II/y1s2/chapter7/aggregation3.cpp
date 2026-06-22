#include<iostream>
using namespace std;

class Officer{
    private:
    string name;
    int id;

    public:
    Officer(string n="",int _id=0):name(n),id(_id){};
    void set(string _name,int _id){
        name=_name;
        id=_id;
    }
    void print(){
        cout<<"Officer : "<<name<<"  "<<id<<endl;
    }
};
class Offender{
    private:
    string name;
    string ic;
    string address;
    public:
    Offender(string _name,string id,string add){
        name=_name;
        ic=id;
        address=add;
    }
    void set(string _name="",string id="",string add=""){
        name=_name;
        ic=id;
        address=add;
    }
    void print(){
        cout<<"Offender : "<<name<<"  "<<ic<<" "<<address<<endl;
    }
};
class Summon{
    private:
    int code;
    Officer *officer;
    Offender offender;
    public:
    Summon(int cod=0,string name="",string id="",string add=""):code(cod),offender(name,id,add){};
       
    void addOfficer(string a,int b){
        officer=new Officer;
        officer->set(a,b);
    }
    void removeOfficer(){
        delete officer;
        officer=NULL;
    }
    void print(){
        cout<<endl<<"Summon COde: "<<code<<endl;
        offender.print();
        officer->print();
    }
};
int main(){
    Officer a("ALI",7466447);
    Offender b("KAssim","6834868364","no1");
    Summon c(12,"dfhdh","479797","T-2");
    c.addOfficer("AHMAD",9070);
    a.print();
    b.print();
    c.print();
    c.removeOfficer();
}