 #include <iostream>
using namespace std;
        

int main()
{
    int count;
    int highest;
    int numbers[10];
    highest = numbers[0];
    
    for(int i=0;i<10;i++){
      cout<<"Enter 10 value "<<i+1<<":";
      cin>>numbers[i];
    }
    
  for (int i = 1; i < 10; i++){
    if (numbers[i] > highest)
    highest = numbers[i];
  }
  cout<<highest;

return 0; 
}
      
