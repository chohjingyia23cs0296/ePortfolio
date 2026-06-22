#include <iostream>
#include<string>
#define PI 3.14
using namespace std;
// function prototypes
float areaCircle(int );
float areaRect(int , int );
int getParam(string );
void setParam(int &, int &);
void setParam(int &, int &, int &);
char chooseObject();
int main(){
    int width=0,height=0,length=0,radius=0;
    float area=0,volume=0;
    char object;
    object=chooseObject();
    if(object=='b'){
        setParam(width,height,length);
        area=areaRect(width,height);
        volume=area*length;
        cout<<"Volume of cylinder: "<<volume<<"\n\n";

    }else {
        setParam(radius,length);
        area=areaCircle(radius);
        volume=area*length;
        cout<<"Volume of cylinder: "<<volume<<"\n\n";
    }
    return 0;
}
float areaCircle(int radius){
    return PI*radius*radius;
}
float areaRect(int width, int height){
    return width*height;
}
void setParam(int &w, int &h, int &l){
    w=getParam("Width: ");
    h=getParam("Height: ");
    l=getParam("Length: ");
}
void setParam(int &r, int &l){
   r=getParam("Radius: ");
   l=getParam("Length: ");
}
int getParam(string pname){
    int pvalue;
    do{
        cout<<pname;
        cin>>pvalue;
        
    }while(pvalue<=0);
    return pvalue;
}
char chooseObject(){
    char object;
    do{
        cout<<"b-Box\n";
    cout<<"c-Cylinder\n";
    cout<<"Choose object(b/c): ";
    cin>>object;
    }while(object!='b'&&object!='c');
    cout<<"\n";
    return object;
}