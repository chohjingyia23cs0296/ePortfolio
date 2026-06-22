#include<iostream>
#include<vector>
using namespace std;

class Time{
    private:
    int hour;
    int minute;
    public:
    Time(int h,int m):hour(h),minute(m){};
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }    
};
class Passenger{
    protected:
    string name;
    int age;

    public:
    Passenger(string name,int age){
        this->name=name;
        this->age=age;
    }
    virtual void printDetails(){
        cout<<"Name:    "<<name<<"\t"<<"Age:     "<<age<<"      ";
    }
    virtual ~Passenger() {}
}; 
class Kids:public Passenger{
    private:
    string parentName;
    public:
    Kids(string _parentName,string _name,int _age):Passenger(_name,_age){
        parentName=_parentName;
    }
    void printDetails()override{
        Passenger::printDetails();
        cout<<"Parents Name:      "<<parentName<<"\n";
    }
};
class Adults:public Passenger{
    private:
    string job;
    public:
    Adults(string _job,string _name,int _age):Passenger(_name,_age){
        job=_job;
    }
    void printDetails()override{
        Passenger::printDetails();
        cout<<"Job Title      "<<job<<"\n";
    }
};
class Flight{
    private:
    string id;
    string destination;
    Time depart;
    Time arrival;
    vector<Passenger*> passengerList;
    public:
    Flight(string _id,string _destination,Time d,Time a):id(_id),destination(_destination),depart(d),arrival(a){};
    void addPassenger(Passenger* p) {
        passengerList.push_back(p);
    }

    void printInfo(){
        cout<<"Flight Number:   "<<id<<"\n";
        cout<<"Destination:     "<<destination<<"\n";
        cout<<"Departure:       "<<depart.getHour()<<":"<<depart.getMinute()<<"\n";
        cout<<"Arrival:         "<<arrival.getHour()<<":"<<arrival.getMinute()<<"\n";

        cout << "Number of Passengers: " << passengerList.size() << "\n";
        int numAdults = 0;
        int numKids = 0;
        for (Passenger* p : passengerList) {
            if (dynamic_cast<Adults*>(p)) numAdults++;
            if (dynamic_cast<Kids*>(p)) numKids++;
        }
        cout << "Number of Adults: " << numAdults << "\n";
        cout << "Number of Kids: " << numKids << "\n\n";
        cout << "Passengers Details:\n";
        for (Passenger* p : passengerList) {
            p->printDetails();
        }
    }
    ~Flight() {
        for (Passenger* p : passengerList) {
            delete p;
        }
    }
    
};
int main(){
    Time departure(8,10);
    Time arrival(9,00);
    Flight flight("NAS7921","Johore Bahru",departure,arrival);

    flight.addPassenger(new Adults("Lecturer", "Ali", 34));
    flight.addPassenger(new Adults("Student", "Goh", 25));
    flight.addPassenger(new Kids("Ali", "Azmi", 3));

    flight.printInfo();


    return 0;
}