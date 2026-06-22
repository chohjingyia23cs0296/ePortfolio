//Program 1
#include <iostream>
using namespace std;
class Date {
private:
int day;
int month;
int year;
public:
// (i) Default constructor prototype
Date();
// (ii) Constructor with 3 parameters prototype
Date(int ,int,int);
int getDay() {
return day;}
int getMonth() {
return month;}
int getYear() {
return year;}
};
// (i) Default constructor definition
Date::Date(){
    day=0;
    month=0;
    year=0;
}
// (ii) Constructor with 3 parameters definition
Date::Date(int d,int m,int y){
    day=d;
    month=m;
    year=y;
}
int main() {
// (iii) Creation of Date object called birthDate
Date birthDate;
// (iv) Creation of Date object pointer called datePtr
Date *datePtr;
// (v) Create a Date object named sunset and pass 7, 35, and 45 as parameters
Date(7,35,45);
return 0;
}

//Program 2
#include<iostream>
using namespace std;

class Length{
private:
int len_inches;
public:
Length(int feet, int inches){
    len_inches=12*feet + inches;
    }
int getFeet(){
    return len_inches/12;
    }
int getInches(){
    return len_inches%12;
    }

friend bool operator< (Length, Length );
friend bool operator== (Length a, Length b) ;
};

bool operator<(Length a,Length b){
    return a.len_inches<b.len_inches;
}

bool operator==(Length a,Length b){
    return a.len_inches>b.len_inches;
}
int main(){

    Length lens[4]={
        Length(48,0),
        Length(48,0),
         Length(48, 0), 
         Length(60, 0)
    };
    for(int i = 0; i < 4; ++i) {
        for(int j = i + 1; j < 4; ++j) {
            if(lens[i].getFeet() == lens[j].getFeet() && lens[i].getInches() == lens[j].getInches()) {
                cout << "Same length at indexes " << i << " and " << j << endl;
            }
        }
    }
    int shortest_index=0;
    for(int i = 1; i < 4; ++i) {
        if(lens[i].getFeet() < lens[shortest_index].getFeet() || 
          (lens[i].getFeet() == lens[shortest_index].getFeet() && lens[i].getInches() < lens[shortest_index].getInches())) {
            shortest_index = i;
        }
    }
    cout << "Shortest length in feet is " << lens[shortest_index].getFeet() << " feet at index " << shortest_index << endl;
    
    int longest_index = 0;
    for(int i = 1; i < 4; ++i) {
        if(lens[i].getFeet() > lens[longest_index].getFeet() || 
          (lens[i].getFeet() == lens[longest_index].getFeet() && lens[i].getInches() > lens[longest_index].getInches())) {
            longest_index = i;
        }
    }
    cout << "Longest length in feet is " << lens[longest_index].getFeet() << " feet at index " << longest_index << endl;
    return 0;
}


//Project 3
#include<iostream>
#include<cstring>
using namespace std;

class Month {
private:
    string name;
    int monthNumber;

public:
    Month(string name) {
        if(name == "January")
            monthNumber = 1;
        else if (name == "February") 
            monthNumber = 2;
        else if (name == "March") 
            monthNumber = 3;
        else if (name == "April") 
            monthNumber = 4;
        else if (name == "May")
            monthNumber = 5;
        else if (name == "June") 
            monthNumber = 6;
        else if (name == "July") 
            monthNumber = 7;
        else if (name == "August") 
            monthNumber = 8;
        else if (name == "September") 
            monthNumber = 9;
        else if (name == "October") 
            monthNumber = 10;
        else if (name == "November") 
            monthNumber = 11;
        else if (name == "December") 
            monthNumber = 12;
        else {
            cout << "Invalid month name. Setting to January." << endl;
            name = "January";
            monthNumber = 1;
        }
        this->name = name;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const{
        return name;
    }

    Month& operator++() {
        ++monthNumber;
        if (monthNumber > 12) {
            monthNumber = 1;
            name = "January";
        } else {
            switch (monthNumber) {
                case 1: name = "January"; break;
                case 2: name = "February"; break;
                case 3: name = "March"; break;
                case 4: name = "April"; break;
                case 5: name = "May"; break;
                case 6: name = "June"; break;
                case 7: name = "July"; break;
                case 8: name = "August"; break;
                case 9: name = "September"; break;
                case 10: name = "October"; break;
                case 11: name = "November"; break;
                case 12: name = "December"; break;
                default: break;
            }
        }
        return *this;
    }

    Month operator++(int) {
        Month temp = *this;
        ++(*this);
        return temp;
    }
    
    friend ostream& operator<<(ostream& out, const Month& month);
    friend istream& operator>>(istream& in, Month& month);
};

ostream& operator<<(ostream& out, const Month& month) {
    out << month.getName();
    return out;
}

istream& operator>>(istream& in, Month& month) {
    int monthNum;
    in >> monthNum;
    if (monthNum >= 1 && monthNum <= 12) {
        month.monthNumber = monthNum;
        switch (monthNum) {
            case 1: month.name = "January"; break;
            case 2: month.name = "February"; break;
            case 3: month.name = "March"; break;
            case 4: month.name = "April"; break;
            case 5: month.name = "May"; break;
            case 6: month.name = "June"; break;
            case 7: month.name = "July"; break;
            case 8: month.name = "August"; break;
            case 9: month.name = "September"; break;
            case 10: month.name = "October"; break;
            case 11: month.name = "November"; break;
            case 12: month.name = "December"; break;
            default: break;
        }
    } else {
        cout << "Invalid month number. Setting to January." << endl;
        month.name = "January";
        month.monthNumber = 1;
    }
    return in;
}


int main() {
    Month m1("January");
    cout << "Current month: " << m1 << endl;
    
    ++m1;
    cout << "After prefix increment: " << m1 << endl;
    
    Month m2 = m1++;
    cout << "After postfix increment: " << m2 << endl;
    
    cout << "Enter a month name: ";
    cin >> m1;
    cout << "You entered: " << m1 << endl;

    return 0;
}
