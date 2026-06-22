#include <iostream>
using namespace std;

class B {
private:
    int m;
protected:
    int n;
public:
    void setM(int value) {
        m = value;
    }
    int getM() const {
        return m;
    }
    void setN(int value) {
        n = value;
    }
    int getN() const {
        return n;
    }
    int calc() const {
        return m * n;
    }
};

class D : public B {
private:
    double q;
protected:
    double r;
public:
    void setQ(double value) {
        q = value;
    }
    double getQ() const {
        return q;
    }
    void setR(double value) {
        r = value;
    }
    double getR() const {
        return r;
    }
    double calc() const {
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
    cout << "Class D - m * n: " << objD.B::calc() << endl; // Calling superclass calc method
    cout << "Class D - q * r: " << objD.calc() << endl; // Calling overridden calc method

    return 0;
}
