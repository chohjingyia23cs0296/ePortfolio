// Program 7.8
#include <iostream>
using namespace std;

class classA {
    int val1;
    string val2;
    
public:
    classA(int val1, string val2) {
        this->val1 = val1;
        this->val2 = val2;
    }
    
    int getValue() {
        return val1 * 100;
    }
    
    string getStringA() {
        return val2;
    }
};

class classC {
    string value1;
    string value2;
    
public:
    classC(string value1, string value2) {
        this->value1 = value1;
        this->value2 = value2;
    }
    
    string getStringC() {
        return value1 + " " + value2;
    }
};

class classB {
    string valA;
    int valB;
    classA *valC;
    classC valD;
    
public:
    classB(string valA, int valB, classA *C) : valD("Good", "Luck") {
        this->valA = valA;
        this->valB = valB;
        valC = C;
    }
    
    void print() {
        cout << "In class A: " << valC->getStringA() << " " << valC->getValue() << endl;
        cout << "In class C: " << valD.getStringC() << endl;
        cout << "In class B: " << valA << " " << valB * 100 << endl;
    }
};

int main() {
    classA *obj1 = new classA(50, "My target");
    classB obj2("For You", 10, obj1);
    obj2.print();
    return 0;
}
