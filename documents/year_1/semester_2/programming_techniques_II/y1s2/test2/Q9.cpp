#include<iostream>
#include<string>
using namespace std;
class Line{
    private:
    int m;
    int c;
    public:
    Line(int m_=1,int c_=0){
        m=m_;
        c=c_;
    }
    void read(){
        cout<<"Enter the slope (m) and y-intercept of a line (c) => ";
        cin>>m>>c;

    }
    Line operator-(const Line&obj){
        Line result;
        result.m=m-obj.m;
        result.c=c-obj.c;
        return result;
    }
    bool operator!=(const Line&obj){
        if(m*obj.m!=-1)
        return true;
        else
        return false;
}
    string toString(){
        if(m==-1){
            if(c==0)
            return "y=-x";
            else if(c>0)
            return "y=-x+"+to_string(c);
            else
            return"y=-x-"+to_string(c);
        }else if(m==1){
            if(c==0)
            return "y=x";
            else if(c>0)
            return "y=x+"+to_string(c);
            else
            return"y=x-"+to_string(c);
        }else {
            if(c==0)
            return "y="+to_string(m)+"x";
            else if(c>0)
            return "y="+to_string(m)+"x+ "+to_string(c);
            else
            return"y="+to_string(m)+"x"+to_string(c);
        }
    }
    friend void printLines( Line line[3]){
        for(int i=0;i,3;i++){
            cout<<"Line "<<i+1<<"slope(m)= "<<line[i].m<<", y-intercept(c) = "<<line[i].c<<", equation: "<<line[i].toString()<<endl;
        }
    }   
};
int main(){
    Line line[3]={Line(1,5),Line(1,0),Line(1,0)};
    cout<<"ORIGINAL LINES\n";
    printLines(line);
    cout<<"\nSet the second line from user input\n";
    line[1].read();

    cout<<"UPDATED LINES\n";
    line[2]=line[0]-line[1];
    printLines(line);
    if(line[0]!=line[1])
    cout<<"The first line is perpendicular to the last line";
    else
    cout<<"The first line is not perpendicular to the last line";
    return 0;
    
}