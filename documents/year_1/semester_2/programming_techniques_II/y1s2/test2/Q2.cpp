#include<iostream>
#include<string>
using namespace std;

class Line{
    private:
    int c;
    int m;
    public:
    Line(int m_=1,int c_=0){
        m=m_;
        c=c_;
        
    }
    void read(){
        cout<<"Enter the slope (m) and y-intercept of a line (c) =>";
        cin>>m>>c;
    }
    Line operator-(const Line&obj){
        Line result;
        result.m=m-obj.m;
        result.c=c-obj.c;
        return result;
    }
    bool operator!=(const Line&obj){
        return m*obj.m!=-1;
    }
    string toString()const{
            if(m == 1){
                if(c > 0)
                    return "y = x + " + to_string(c) ;
                else if(c == 0)
                    return "y = x" ;
                else    
                    return "y = x - " + to_string(c) ;
            }else if(m==-1){
                if(c > 0)
                    return "y = -x + " + to_string(c) ;
                else if(c == 0)
                    return "y = -x" ;
                else    
                    return "y = -x - " + to_string(c) ;
            }else {
                if(c > 0)
                    return "y = "+to_string(m)+ " x + " + to_string(c) ;
                else if(c == 0)
                    return "y = "+to_string(m)+" x" ;
                else    
                    return "y = "+to_string(m)+ " x + " + to_string(c) ;
            }
    }
    friend void printLines(const Line&obj){
        cout<<" slope(m) = "<<obj.m<<", y-intercept(c) = "<<obj.c<<", equation: "<<obj.toString()<<"\n";
    }

};
int main(){
    Line line[]={Line(1,5),Line(1,0),Line(1,0)};
    cout<<"ORIGINAL LINES\n";
    for(int i=0;i<3;i++){
        cout<<"Line "<<i+1;
        printLines(line[i]);
    }
    cout<<"\nSet the second line from user input\n";
    line[1].read();

    cout<<"\nUPDATED LINES\n";
    for(int i=0;i<2;i++){
        cout<<"Line "<<i+1;
        printLines(line[i]);
    }
    line[2]=line[0]-line[1];
    cout<<"Line 3";
    printLines(line[2]);
    

    if(line[0]!=line[2])
    cout<<"\nThe first line is not perpendicular to the last line";
    else
    cout<<"\nThe first line is perpendicular to the last line";

     
     return 0;
}