 #include <iostream>
using namespace std;
        

int main()
{
    int count;
    int lowest;
    int numbers[10];
    
    
    for(int i=0;i<10;i++){
      cout<<"Enter 10 value "<<i+1<<":";
      cin>>numbers[i];
    }
    lowest = numbers[0];//must be here
  for (count = 1; count < 10; count++){
    if (numbers[count] < lowest)
    lowest = numbers[count];
  }
  cout<<lowest;

return 0; 
}
      
