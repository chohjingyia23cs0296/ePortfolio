#include <iostream>
using namespace std;

int main() {
    const int size = 4;
    int arr[size];
    //int arr[size] = {2, 5, 8, 2, 3, 5, 8, 10, 12, 3};
    for(int i=0;i<size;i++){
        cout<<"Num: ";
        cin>>arr[i];
    }

    for(int i=0;i<size;i++){
        bool isDuplicate=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                isDuplicate=1;
                break;
        }
        }if(!isDuplicate){
            cout<<arr[i];
        }
    }
    

    return 0;
}
