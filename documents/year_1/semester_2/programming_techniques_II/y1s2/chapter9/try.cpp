#include<iostream>
using namespace std;

int main(){
    int choice;
    cout<<"Enter choice: ";
    cin>>choice;
    try{
        if(choice==1)
        throw "This is const c-string";
        else if(choice==2){
            char cStr[]="This is a c-string";
            throw cStr;
        }else if (choice==3){
            string cppStr="This is a cpp-string";
            throw cppStr;
        }
        
    }
    catch(const char*msg){//a literal c-string
        cout<<"Caught msg"<<msg;
    }
    catch(char*msg){//c-string
        cout<<"Caught msg"<<msg;
    }
    catch(string msg){//c++ string
        cout<<"Caught msg"<<msg;
    }

}