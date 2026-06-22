#include <iostream>
using namespace std;

class Length{
    private:
    int len_inches;
    public:
    Length(int feet,int inches){
        len_inches=12*feet+inches;
    }

    int getFeet(){
            return len_inches/12;
    }
    int getInches(){
        return len_inches%12;
    }
    friend bool operator<(Length,Length);
    friend bool operator==(Length a,Length b);
};
bool operator<(Length a,Length b){
    if(a.len_inches<b.len_inches){
        return true;
    }
}
bool operator==(Length a,Length b){
    if(a.len_inches==b.len_inches){
        return true;
    }
}
int main(){
    Length lens[4]={
        Length(48,0),
        Length(48,0),
         Length(48, 0), 
         Length(60, 0)
    };
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(lens[i].getFeet()==lens[j].getFeet()&&lens[i].getInches()==lens[j].getInches()){
                cout<<"Same length at indexes "<<i<<" and "<<j<<endl;
            }
        }
    }
    int longest_index = 0;
    for(int i = 1; i < 4; ++i) {
        if(lens[i].getFeet() > lens[longest_index].getFeet() || 
          (lens[i].getFeet() == lens[longest_index].getFeet()&& lens[i].getInches() > lens[longest_index].getInches())) {
            longest_index = i;
        }
    }
    cout << "Longest length in feet is " << lens[longest_index].getFeet() << " feet at index " << longest_index << endl;
    
    int shortest_index=0;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(lens[shortest_index].getFeet()>lens[i].getFeet()&&lens[shortest_index].getInches()>lens[i].getInches()){
                shortest_index=i;
            }
    }
    }
    cout<<"Shortest length in feet is "<<lens[shortest_index].getFeet()<<" feet at index "<<shortest_index<<endl;


    return 0;
}