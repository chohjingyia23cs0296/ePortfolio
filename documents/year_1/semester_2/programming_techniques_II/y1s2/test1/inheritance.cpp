//Inheritance is the ability of one class to extend the capabilities of another
#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
    string species;
    Animal(const string&s):species(s){};
    void sleep()const{
        cout<<"The "<<species<<"is sleeping"<<endl;
    }
    void eat()const{
        cout<<"The "<<species<<"is eating"<<endl;
    }
};
class Cat:public Animal{
    public:
    string name;
    Cat(const string&n):Animal("cat"),name(n){};
    void meow(){
        cout<<name<<"says :Meow"<<endl;
    }

};
int main(){
    Cat mycat("Buddy");
    mycat.eat();
    mycat.sleep();
    mycat.meow();

}