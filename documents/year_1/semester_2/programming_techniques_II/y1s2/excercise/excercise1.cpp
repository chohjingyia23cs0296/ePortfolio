//2a
//Aggregation is a special form of association,which represents an ownership relationship between two classes
//Association indicates the relationship between objects.It represents a general binary relationship that describes an activity between two classes
//2b
//They're totally a different. A friend class has access to all the friendly class's members, an aggregated class is just used by the other class.


/*The Person class is a basic class with a name attribute.
The TextBook class composes a Person object, meaning each TextBook is associated with an author who is a Person.
The Course class composes both a TextBook object and a Person object, meaning each Course includes a TextBook and an instructor who is a Person.
*/
// Program 7.6
#include <iostream>
#include<string>
using namespace std;

class Officer {
private:
    string name;
    int id;
public:
    Officer(string oname = "", int oid = 0) {
        name = oname; id = oid;
    }
    void set(string a, int b) {
        name = a; id = b;
    }
    void print() {
        cout << "Officer : " << name << " " << id << endl;
    }
};

class Offender {
private:
    string name, ic, address;
public:
    Offender(string oname="", string id="", string add="") {
        name = oname; address = add; ic = id;
    }
    void set(string a, string b, string c) {
        name = a; ic = b; address = c;
    }
    void print() {
        cout << "Offender :" << name << " " << ic << " " << address << endl;
    }
};

class Summon {
private:
    int code;
    Officer *officer;
    Offender offender;
public:
    Summon(int cod=0, string name="", string id="", string add = "") {
        code = cod; offender.set(name, id, add);
    }
    void addOfficer(string a, int b) {
        officer = new Officer; officer->set(a, b);
    }
    void removeOfficer() {
        delete officer; officer = NULL;
    }
    void print() {
        cout << endl << "Summon Code : " << code << endl;
        offender.print();
        officer->print();
    }
};

int main() {
    Officer a("ALI", 75381);
    Offender b("KASSIM", "841203015311", "NO 1 JALAN PS 13 TAMAN PERMATA SINAR");
    Summon c(12, "SELAMAT", "992112035621", "NO 3 JALAN PC 31 TAMAN PERMATA CAHAYA");
    
    c.addOfficer("AHMAD", 87611);
    a.print();
    b.print();
    c.print();
    c.removeOfficer();

    return 0;
}
