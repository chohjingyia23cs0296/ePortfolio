#include<iostream>
using namespace std;
class ClassName{
    private:int x,y;
    public:
    ClassName readData(){
        ClassName temp;
        cout<<"Please input x and y"<<endl;
        cin>>x;
        cin>>y;
        temp.x=x+2;
        temp.y=y*3;
        return temp;
    };
    void display(){
    cout<<"x: "<<x<<endl<<"y "<<y<<endl;
}
};
int main(){
    ClassName o1,o2;
    o2=o1.readData();
    o1.display();
    o2.display();
    return 0;
}
