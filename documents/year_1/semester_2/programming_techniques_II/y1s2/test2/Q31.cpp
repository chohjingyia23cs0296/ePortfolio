#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

class WordNumber{
    private:string data;

    public:
        WordNumber(string d="zero")
        {
            data=d;
        }
    WordNumber(int n)
        {
            if(n==0)
                data="zero";
            else if(n==1)
                data="one";
            else if(n==2)
                data="two";
            else if(n==3)
                data="three";
            else if(n==4)
                data="four";
            else if(n==5)
                data="five";
            else if(n==6)
                data="six";
            else if(n==7)
                data="seven";
            else if(n==8)
                data="eight";
            else if(n==9)
                data="nine";
            else
            {
                data="";
            }
        }
    void setData(string d){
        for(int i=0;i<d.length();i++){
            d[i]=tolower(d[i]);
        }
        data=d;
    }
    string getData()const{
        return data;
    }
    int stringtoInt(){
        int d;
        if(data=="zero")
        d=0;
        else if(data=="one")
        d=1;
        else if(data=="two")
        d=2;
        else if(data=="three")
        d=3;
        else if(data=="four")
        d=4;
        else if(data=="five")
        d=5;
        else if(data=="six")
        d=6;
        else if(data=="seven")
        d=7;
        else if(data=="eight")
        d=8;
        else if(data=="nine")
        d=9;
        else
        d=0;
        return d;
    }
    friend bool operator>( WordNumber&left, WordNumber&right){
        if(left.stringtoInt()>right.stringtoInt())
        return true;
        else
        return false;
    }
    int operator+(int n){
        return stringtoInt()+n;
    }
    string operator+(string n){
        return data+n;
    }
    WordNumber operator+( WordNumber &obj){
        int n=stringtoInt()+obj.stringtoInt();
        string str;
        if(n==0)
                str="zero";
            else if(n==1)
                str="one";
            else if(n==2)
                str="two";
            else if(n==3)
                str="three";
            else if(n==4)
                str="four";
            else if(n==5)
                str="five";
            else if(n==6)
                str="six";
            else if(n==7)
                str="seven";
            else if(n==8)
                str="eight";
            else if(n==9)
                str="nine";
            else
            {
                str="";
            }
            return str;

    }
    
    friend void printObject(WordNumber&obj){
        cout<<"("<<obj.data<<", "<<obj.stringtoInt()<<")"<<endl;
    }
    friend void printArray(WordNumber&obj){
        printObject(obj);
    }
    
};

int main()
{
    WordNumber objects[4]={WordNumber(),WordNumber(1),WordNumber(2),WordNumber("three")};
    cout<<"Original objects"<<endl;
    for (int i=0;i<4;i++)
    {
        printArray(objects[i]);
    }
    cout<<endl;
    cout<<"To modify the objects with user inputs"<<endl;
    string str;
    for(int i=0;i<4;i++)
    {
        cout<<"Enter a number in word=> ";
        cin>>str;
        objects[i].setData(str);
        cout<<endl;
    }
    cout<<"Modified objects"<<endl;
    for (int i=0;i<4;i++)
    {
        printArray(objects[i]);
    }
    cout<<endl;
    WordNumber sum;
    for(int i=0;i<4;i++)
    {
        sum=sum+objects[i];
    }
    cout<<"The sum: ";
	printObject(sum);
    
    WordNumber largest;
    for(int i=0;i<4;i++)
    {
        if(largest.stringtoInt()<objects[i].stringtoInt())
        {
            largest.setData(objects[i].getData());
        }
    }
    cout<<endl<<"The largest: ";
    printObject(largest);
    cout<<endl<<"To add object with a string"<<endl;
    cout<<"Enter a string=> ";
    string l;
    cin>>l;
    cout<<"The result of adding object with the input string"<<endl;
    cout<<sum+l;
    return 0;
}