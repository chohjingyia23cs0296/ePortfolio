#include <iostream>
using namespace std;

int main() {   
    int size;
    cout << "How big is your cat: ";
    cin >> size;

    for (int i = 1; i <=size; i++) {
        for (int j = 0; j < size - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        for (int a = 1; a <= size - i+1; a++) {
            cout << " ";
        }
        for(int j=1;j<=size-i+1;j++){
            cout<<" ";
        }
        for(int c=1;c<=2*i-1;c++){
            cout<<"*";
        }
        cout << "\n";
    }
    
        for(int d=1;d<=size-3;d++){
            for(int e=1;e<=4*size;e++){
                //2(2*n-1)+2 = 4n
                cout<<"*";
        }cout<<"\n";
    }
        for(int e=1;e<=size*8;e++){
            cout<<"*";
        }cout<<"\n";

        for(int f=1;f<=size-3;f++){
            for(int g=1;g<=size*6;g++){
                cout<<"*";
            }cout<<"\n";
            
        }
        for(int g=1;g<=size;g++){
            for(int m=1;m<=size/2;m++){
                cout<<"*"; 
            }
        
        for(int z=1;z<=size/1.5;z++){
                cout<<" ";       
            }
        for(int n=1;n<=size/2;n++){
                cout<<"*";
        }
        for(int o=1;o<=size*2;o++){
            cout<<" ";
        }
        for(int p=1;p<=size/2;p++){
             cout<<"*";
        }
        for(int r=1;r<=size/1.5;r++){
             cout<<" ";
        }
        for(int s=1;s<=size/2;s++){
            cout<<"*";
        }

        cout<<"\n"; 
        }
    return 0;
}
