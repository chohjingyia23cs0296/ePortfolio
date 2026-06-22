//create a Struct data that store the student id, student fullname, student gpa
//initialize 5 students with the name: Fawwaz, Beh, Ong, Rao, Zikry
//display each student id along with fullname, and his/her gpa
//challenge, simplify the program by using array
#include <iostream>
using namespace std;
struct Student{

  int stuID;
  string stuName;
  double stuGPA;
};

const int SIZE=5;
int main(){
  
  Student student[SIZE]={
    {210, "Fawwaz Abdullah", 3.99},
   {310, "Beh Shu Yie", 3.97},
   {287, "Ong Shun Sheng", 2.67}, 
   {109, "Sudaren Rao", 3.22},
   {524, "Zikry Mahathir", 3.88}
  };
  
  for(int i=0;i<SIZE;i++){
    cout<<"Student ID: "<<student[i].stuID<<endl;
    cout<<"Student Name: "<<student[i].stuName<<endl;
    cout<<"Student Name: "<<student[i].stuGPA<<endl;
    cout<<"\n";
  }


    return 0;

}