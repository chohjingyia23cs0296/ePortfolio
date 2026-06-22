#include<iostream>
using namespace std;

class FeetInches{

    private:
    int inches;
    int feet;

    public:
    FeetInches(int i,int f){
        inches=i;
        feet=f;
    }

    int getInches()const{
        return inches;
    }
    int getFeet()const{
        return feet;
    }

    bool operator>(const FeetInches &right){
        bool status;
        if(feet>right.feet){
            status=true;
        }else if(feet==right.feet&&inches>right.inches){
            status=true;
        }else{
            status=false;
        }
        return status;
    }


};
int main(){

    FeetInches value1(40,60);
    FeetInches value2(50,70);
    if (value1 > value2) {
        cout << "Value 1 is greater than Value 2" << endl;
    } else {
        cout << "Value 1 is not greater than Value 2" << endl;
    }


}

    

