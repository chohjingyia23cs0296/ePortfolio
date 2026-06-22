#include<iostream>
using namespace std;

class B {
private:
    int m; 

protected:
    int n; 

public:
    // Setter and getter for m
    void setM(int value) {
        m = value;
    }

    int getM() const {
        return m;
    }

    // Setter and getter for n
    void setN(int value) {
        n = value;
    }

    int getN() const {
        return n;
    }

    // Public virtual member function
    virtual double calc() const {
        return m * n;
    }
};
class D : public B {
protected:
    float q; 
    float r; 

public:
    // Setter and getter for q
    void setQ(float value) {
        q = value;
    }

    float getQ() const {
        return q;
    }

    void setR(float value) {
        r = value;
    }

    float getR() const {
        return r;
    }
    
    virtual double calc() const override {
        return q * r;
    }
};



int main() {
    B objB;
    objB.setM(3);
    objB.setN(4);
    cout << "Class B - m * n: " << objB.calc() << endl;

    D objD;
    objD.setM(3);
    objD.setN(4);
    objD.setQ(2.5);
    objD.setR(1.5);
    cout << "Class D - m * n: " << objD.B::calc() << endl; 
    cout << "Class D - q * r: " << objD.calc() << endl;

    return 0;
}
