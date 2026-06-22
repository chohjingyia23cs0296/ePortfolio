//Encapsulation is a key concept in working with objects:Combinign attributes and methods in one package 
//and hiding the imlpementation of the data from the user of the object
#include <iostream>
using namespace std;
 
class Passport {
private:
  string country_of_origin = "United States";
public:
  int passport_number;
  string passport_name;
  void dothis() {
        cout << passport_name << "'s " << country_of_origin << " passport number is " << passport_number;
  }
};
 
int main() {

  Passport mypassport;
  mypassport.passport_number = 476896564;
  mypassport.passport_name = "Reginald Higgins";
  mypassport.dothis();
  return 0;
}
 