// Exercise 2
// Programming Technique II
// Semester 2, 2023/2024
// Date: 5-5-2024
// Section: 1
// Member 1's Name: CHOH JING YI
// Member 2's Name: LIOW JIA FENG

#include<iostream>
#include<cstring>
using namespace std;

class software{
    string soft1,soft2;
    public:
    software();
    software(string x,string y){
        soft1=x;
        soft2=y;
    }
    software(const software& a){
        soft1=a.soft1;
        soft2=a.soft2;
    }
    ~software(){
        cout<<soft1<<" and "<<soft2<<" are destroyed from software\n";
    }
    void getData();
    friend ostream& operator<<(ostream&os,const software&a){
        os<<a.soft1<<endl<<a.soft2;
        return os;
    }

};
software::software(){
    soft1="DEV-C++";
    soft2="RStudio";
}
void software::getData(){
    string a,b;
    cout<<"Enter 2 software\n";
    cin>>a>>b;
    soft1=a;
    soft2=b;
}

class hardware
{
    char hard1[20];
    char hard2[20];

    public:
    hardware();
    hardware(char a[],char b[])
    {
        strcpy(hard1,a);
        strcpy(hard2,b);
    }
    hardware(const hardware &x)
    {
        strcpy(hard1,x.hard1);
        strcpy(hard2,x.hard2);
    }
    ~hardware()
    {
        cout<<hard1<<" and "<<hard2<<" are destroyed from hardware\n";
    }
    void getData();
    friend ostream& operator<<(ostream& os,const hardware &a)
    {
        os<<a.hard1<<endl<<a.hard2<<endl;
        return os;
    }

};
hardware::hardware()
{
    strcpy(hard1,"laptop");
    strcpy(hard2,"mouse");
}

void hardware::getData()
{
    char a[20],b[20];
    cout<<"Enter 2 hardware\n";
    cin>>a>>b;
    strcpy(hard1,a);
    strcpy(hard2,b);
}
int main(){

    char c[20]="mouse pad",d[20]="headset";
    hardware hard[3]={hardware(),hardware(c,d),hardware()};
    hardware newhard(hard[1]);
    string s2_1="python",s2_2="matlab";
    cout<<"Software\n";
    cout<<"---------\n";
    software *soft1=new software;
    cout<<*soft1<<endl<<endl;
    soft1->getData();

    software *soft2=new software(s2_1,s2_2);
    soft1=new software(*soft2);
    cout<<endl;
    
    cout<<"Software:Pointer of Object call\n";
    soft2->getData();

    cout<<"\nSoftware: Copy constructor\n";
    cout<<*soft1<<endl;

    cout<<"\nHardware\n";
    cout<<"-----------\n";
    cout<<hard[0];
    cout<<endl;
    hard[0].getData();

    cout<<"\nHardware: Array of object call\n";
    hard[1].getData();
    cout<<endl<<endl;
    
    hard[2].getData();
    cout<<endl;

    cout<<"Hardware: Copy constructor\n";
    cout<<newhard<<endl;
    cout<<"Destructor call\n";

    hard[0].~hardware();
    hard[2].~hardware();
    hard[1].~hardware();
    newhard.~hardware();

    delete soft2;
    delete soft1;
    delete[]hard;

    return 0;


}
