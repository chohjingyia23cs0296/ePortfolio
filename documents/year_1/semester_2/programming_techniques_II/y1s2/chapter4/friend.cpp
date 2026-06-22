#include<iostream>
using namespace std;

class FriendClass
{

};
class NewClass
{
public:
friend class FriendClass;
// declares entire class as a friend
// of this claFriendClass ss

};
class Rectangle{
    private:
    double length;

    public:
    Rectangle(double len){
    length=len;
    }
   
    void setLength(double len){
        length=len;
    }
    
    double getLength(){
        return length;
    }

};
int main(){

    Rectangle otherRectangle(0.0);
    Rectangle *rPtr=&otherRectangle;
    rPtr->setLength(12.5);//either one
    (*rPtr).setLength(12.5);//either one
    cout << "Length of the rectangle: " << rPtr->getLength() <<endl;

    return 0;

}
    

