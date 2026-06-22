#include<iostream>
#include<string>

using namespace std;
const int size=3;

class Line{
    private:
    int m;
    int c;
    
    public:
    Line(int _m=1,int _c=0){
        m=_m;
        c=_c;
    }
    void read(){
        cout<<"Set the second line from user input"<<endl;
        cout<<"Enter the slope (m) and y-intercept of a line (c) => ";
        cin>>m>>c;
    }
    Line operator-(const Line&obj){
        Line result;
        result.m=m-obj.m;
        result.c=c-obj.c;
        return result;;
    }
    bool operator!=(const Line&obj){
        return m* obj.m != -1;
    }
    string toString(){
        if(m==1){
            if(c==0)
            return "y = x";
            else
            return "y = x + "+ to_string(c);

        }else if(m==-1){
            if(c==0)
            return "y = -x";
            else
            return "y = -x "+ c;
        }
        else if(m==0){
            return "y = "+to_string(c);
        }
        else if(m<0){
            if(c>0||c<0)
            return "y = "+to_string(m) +"x"+(c>0 ? " + " : " - ")+to_string(c);
            else if(c==0)
            return "y = "+to_string(m) +"x";
        }
        else if(m>0){
            if(c>0||c<0)
            return "y = "+to_string(m) +"x"+(c>0 ? " + " : " - ")+to_string(c);
            else if(c==0)
            return "y = "+to_string(m) +"x";
        }
        
        
    }
    friend void printLines(Line line[],int size){
        for(int i=0;i<3;i++){
            cout<<"Line"<<i+1<<" slope(m) = "<<line[i].m<<", y-intercept(c) = "<<line[i].c<<", equation:"<<line[i].toString()<<endl;
        }
    }
       

};
int main(){
    Line line[3];
    line[0]=Line(1,5);
    printLines(line,3);
    
    line[1].read();
    cout<<"\nUPDATED LINES\n";

    line[2]=line[0]-line[1];
    printLines(line,3);

    if(line[1]!=line[2]){
        cout<<"The first line is not perpendicular to the last line"<<endl;
    }else{
        cout<<"The first line is perpendicular to the last line"<<endl;
    }
    return 0;

}