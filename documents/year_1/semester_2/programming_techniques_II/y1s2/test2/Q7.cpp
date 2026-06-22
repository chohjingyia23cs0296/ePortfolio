#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class WordNumber{
    private:
    string data;
    public:
    WordNumber(string d="zero"){
        data=d;
    }
    WordNumber(int num){
        if(num==0)
        data="zero";
        else if (num==1)
        data="one";
        else if (num==2)
        data="two";
        else if (num==3)
        data="three";
        else if (num==4)
        data="four";
        else if (num==5)
        data="five";
        else if (num==6)
        data="six";
        else if (num==7)
        data="seven";
        else if (num==8)
        data="eight";
        else if (num==9)
        data="nine";
        else
        data=" ";
    }
    void setData(string d){
        for(int i=0;i<data.length();i++){
            d[i]=tolower(d[i]);
        }
        data=d;
    }
    string getData()const{
        return data;
    }
    int toInt(){
        int temp;
        if(data=="zero")
        temp=0;
        else if(data=="one")
        temp=1;
        else if(data=="two")
        temp=2;
        else if(data=="three")
        temp=3;
        else if(data=="four")
        temp=4;
        else if(data=="five")
        temp=5;
        else if(data=="six")
        temp=6;
        else if(data=="seven")
        temp=7;
        else if(data=="eight")
        temp=8;
        else if(data=="nine")
        temp=9;
        else 
        temp=0;
        
        return temp;
    }
    friend bool operator>( WordNumber&left, WordNumber&right){
        return left.toInt()>right.toInt();
    }
    int operator+( int n){
        return toInt()+n; 
    }
    string operator+(string n){
        return data+n;
    }
    WordNumber operator+( WordNumber&obj){
        string str;
        int num= toInt()+obj.toInt();
        if(num==0)
        str="zero";
        else if (num==1)
        str="one";
        else if (num==2)
        str="two";
        else if (num==3)
        str="three";
        else if (num==4)
        str="four";
        else if (num==5)
        str="five";
        else if (num==6)
        str="six";
        else if (num==7)
        str="seven";
        else if (num==8)
        str="eight";
        else if (num==9)
        str="nine";
        else
        str=" ";

        WordNumber temp;
        temp.data=str;
        return str;
    }
    friend void printObject( WordNumber&obj){
        cout<<"("<<obj.data<<", "<<obj.toInt()<<")\n";
    }
    friend void printArray(WordNumber&obj){
        printObject(obj);
    }
};
int main(){
    WordNumber word[4]={WordNumber(),WordNumber(1),WordNumber("two"),WordNumber("three")};
    for(int i=0;i<4;i++)
    printArray(word[i]);

    string number;
    cout<<"To modify the objects with user inputs\n";
    for(int i=0;i<4;i++){
        cout<<"Enter a number in word=> ";
        cin>>number;
        word[i].setData(number);
        cout<<"\n";
    }
    cout<<"Modified objects\n";

    for(int i=0;i<4;i++)
    printArray(word[i]);
    
    WordNumber sum;
    for(int i=0;i<4;i++){
        sum=sum+word[i];
    }
    cout<<"\nThe sum: ";
    printObject(sum);

    WordNumber largest;
    for(int i=0;i<4;i++){
        if(largest.toInt()<word[i].toInt()){
            largest.setData(word[i].getData());
        }
    }
    cout<<"The largest: ";
    printObject(largest);
    string n;
    cout<<"\nTo add object with a string\n";
    cout<<"Enter a string=>";
    cin>>n;
    cout<<"The result of addding object with the input string\n";
    cout<<sum+n;



}
