#include<iostream>
using namespace std;

class SomeClass{
private:
    int *value;
public:
    SomeClass(int val = 0){
        value = new int; 
        *value = val;
    }
    // Declaration of the copy constructor
    SomeClass(const SomeClass &obj);
    int getVal();
    void setVal(int);
};

// Definition of the copy constructor
SomeClass::SomeClass(const SomeClass &obj) {
    value = new int;
    *value = *obj.value;
}

// Definition of the member function getVal()
int SomeClass::getVal() {
    return *value;
}

// Definition of the member function setVal()
void SomeClass::setVal(int val) {
    *value = val;
}

int main() {
    SomeClass object1(5);
    SomeClass object2 = object1;
    object2.setVal(13);
    cout << object2.getVal(); // Output should be 13
    return 0;
}


