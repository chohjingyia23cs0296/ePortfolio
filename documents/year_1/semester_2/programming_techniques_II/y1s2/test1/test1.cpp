//association
#include<iostream>
using namespace std;
class Person{
    private:string name;
    int age;
    public:
    Person(const string&n,int a):name(n),age(a){};
    void setAge(int newAge){
        age=newAge;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }

};
int main(){
    Person person("jingyi",18);
    cout<<"Person1"<<person.getName()<<person.getAge()<<endl;
    person.setAge(10);
    cout<<"Age: "<<person.getAge();

}
