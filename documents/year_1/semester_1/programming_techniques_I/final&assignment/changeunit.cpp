#include<iostream>
using namespace std;

void showKilometers(double meters){
    double kilometres=meters*0.001;
    cout << meters << " meters is equal to " << kilometres << " kilometres." << endl;
}
void showInches(double meters){
    double inches=meters*39.37;
    cout << meters << " meters is equal to " << inches << " inches." << endl;
}
void showFeet(double meters){
    double feet=meters*3.281;
    cout << meters << " meters is equal to " << feet << " feet." << endl;
}
void displayMenu(){
    cout<<"1. Convert to kilometres\n";
    cout<<"2. Convert to inches\n";
    cout<<"3. Convert to feet\n";
    cout<<"4. Quit the program\n";

}
int main(){
    double meters;
    int choice;

        cout << "Enter the distance in meters: ";
        cin >> meters;

        if (meters < 0) {
            cout << "Distance cannot be negative. Please enter a non-negative value." << endl;
            return 1;
        }
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showKilometers(meters);
                break;
            case 2:
                showInches(meters);
                break;
            case 3:
                showFeet(meters);
                break;
            case 4:
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option from the menu." << endl;
        }

    } while (choice != 4);
}