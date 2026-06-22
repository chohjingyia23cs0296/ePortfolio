#include<iostream>
using namespace std;

class ComplexNumber{
    private:
        int i, j ;

    public: 

        ComplexNumber(){
            i = 0 ;
            j = 0 ;
        }

        ComplexNumber(int _i, int _j){
            i = _i ;
            j = _j ;
        }
        
        
        /*
        ComplexNumber operator+(ComplexNumber c){
            i = this -> i + c.i ;
            j = this -> j + c.j ;
            return *this ;
        }
        */
       
       ComplexNumber operator+(const ComplexNumber &c) const {
    ComplexNumber result;
    result.i = i + c.i;
    result.j = j + c.j;
    return result;
}
        

        void print() const{
            cout << i << " + " << j << "i , " ;
        }
};

int main(){

    ComplexNumber a(0,1) , b(1,2);

    b = a + b ;
    a.print();
    b.print() ;

    return 0 ;
}