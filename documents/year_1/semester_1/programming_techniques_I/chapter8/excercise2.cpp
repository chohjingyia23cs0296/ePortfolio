#include <iostream>
#include <iomanip>
using namespace std;
struct savings
{
        string AccountNumber;
        double AccountBalance ;
        double InterestRate ;
        double AverageMonthlyBalance ;
};

struct movie{
    string nameMovie;
    string director;
    string producer;
    int year_released;
};
int main(){
    savings s;
    movie m;
    s={"ACZ42137-B12-7",4512.59,0.04,4217.07};


          // Write a statement here that lets the user enter the name of a favorite movie. Store the name in the
          // structure variable.
          cout<<"Enter the name of a favorite movie: ";
          getline(cin,m.nameMovie);

          cout << "Director: ";
          getline(cin,m.director);
          // Write a statement here that lets the user enter the name of the movie's director. Store the name in the
          // structure variable.
          cout << "Producer: ";
          getline(cin,m.producer);
          // Write a statement here that lets the user enter the name of the movie's producer. Store the name in the
          // structure variable.
          cout << "Year of release: ";
          cin>>m.year_released;
          // Write a statement here that lets the user enter the year the movie was released. Store the year in the
          // structure variable.
          cout << "Here is data on your favorite movie:\n";
          cout<<"name of movie: "<<m.nameMovie<<endl;
          cout<<"Director: "<<m.director<<endl;
          cout<<"Producer: "<<m.producer<<endl;
          cout<<"Year released :"<<m.year_released<<endl;
          // Write statements here that display the data.  
          // just entered into the structure variable.
     return 0;
}
