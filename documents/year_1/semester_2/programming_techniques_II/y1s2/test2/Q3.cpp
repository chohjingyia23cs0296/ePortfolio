#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

class WordNumber{
    private:
        string data;

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
        void setData(string d)
        {
            
        	for (size_t i = 0; i < d.length(); i++) 
			{
            	d[i] = tolower(d[i]);
        	}
        	data = d;
        }
        string getData()const{
            return data;
        }
        int stringtoint()
        {
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
            friend bool operator >(WordNumber&left, WordNumber&right)
            {
                if(left.stringtoint()>right.stringtoint())
                return true;
                else
                return false;
            }
            int operator +(int n)
            {
                int result;
                result=stringtoint()+n;
                return result;
            }
            string operator +(string n)
            {
                string result;
                result=data+n;
                return result;
            }
            WordNumber operator +(WordNumber&right)
            {
                int n=stringtoint()+right.stringtoint();
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
                return str;
            }
            friend void printObject(WordNumber&obj)
            {
                cout<<"("<<obj.data<<", "<<obj.stringtoint()<<")"<<endl;
            }
            friend void printArray(WordNumber&obj)
            {
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
        if(largest.stringtoint()<objects[i].stringtoint())
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