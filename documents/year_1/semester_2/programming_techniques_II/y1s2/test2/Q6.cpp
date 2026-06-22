#include<iostream>
#include<string>
using namespace std;

class Line{

    private:
    int x1;
    int x2;
    int y1;
    int y2;
    int m;
    int c;
    public:
    Line(int x1_=0,int x2_=1,int y1_=0,int y2_=1){
        x1=x1_;
        x2=x2_;
        y1=y1_;
        y2=y2_;
        m=(y2-y1)/(x2-x1);
        c=y1-m*x1;
    }
    void read(){
        cout<<"Enter m and c => ";
        cin>>m>>c;
    }
    Line operator*(int n){
        Line result;
        result.m=m*n;
        result.c=c*1;
        return result;
    }
    string toString()const{
        if(m==1){
            if(c==0)
            return "y = x ";
            else if(c>0)
            return "y = x + "+to_string(c);
            else 
            return "y = x - "+to_string(c); 
        }else if(m==-1){
            if(c==0)
            return "y = -x ";
            else if(c>0)
            return "y = -x + "+to_string(c);
            else 
            return "y = -x - "+to_string(c); 
        }else {
            if(c==0)
            return "y = "+to_string(m)+"x ";
            else if(c>0)
            return "y = "+to_string(m)+"x + "+to_string(c);
            else 
            return "y = "+to_string(m)+"x - "+to_string(c); 
        }
    }
    int evaluate(int number){
        return m*number+c;
    }
    friend void printLines(const Line&obj){
        cout<<" slope, m ="+to_string(obj.m)+", y-intercept, c = "+to_string(obj.c)+", equation: "+obj.toString()<<"\n";
    }


};
int main(){
    int number;
    Line line[3]={Line(0,8,2,2),Line(),Line()};
    cout<<"ORIGINAL LINES\n";
    for(int i=0;i<3;i++){
        cout<<"Line "<<i+1;
        printLines(line[i]);
    }
    cout<<"\nSet the second line from user input\n";
    line[1].read();
    cout<<"\nSet the last line based on the second line\n";
    cout<<"Enter a number to multiply with =>";
    cin>>number;

    line[2]=line[1]*number;
    cout<<"\nUPDATED LINES\n";
    for(int i=0;i<2;i++){
        cout<<"Line "<<i+1;
        printLines(line[i]);
    }
    cout<<"Line 2 ";
    printLines(line[2]);
    int x;
    int y;
    cout<<"\nTest whether the last line passes a point\n";
    cout<<"Enter the coordinate x and y of the point to be tested =>";
    cin>>x>>y;
    int answer=line[2].evaluate(x);
    if(answer==y)
    cout<<"The line passes through the point";
    else
    cout<<"The line does not pass through the point";

    return 0;
}