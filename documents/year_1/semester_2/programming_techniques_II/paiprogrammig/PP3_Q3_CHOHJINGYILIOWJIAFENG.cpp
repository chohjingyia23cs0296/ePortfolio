#include<iostream>
#include<string>
using namespace std;
const int ARRAY_SIZE=10;
void searchStudent(string searchName, string studentArray[][2]) {
    cout << "Search results:" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (studentArray[i][0].find(searchName) != string::npos) {
            cout << studentArray[i][0] << ", " << studentArray[i][1] << endl;
        }
    }
}

int main(){
    string searchName;
    string studentArray[ARRAY_SIZE][2] = {
        {"Muhamad Husin", "A123456"},
        {"Nor Asma", "A156782"},
        {"Raja Kumar", "A187623"},
        {"Muhamad Ali", "A123908"},
        {"Ali Shah", "A145234"},
        {"Nor Nadia", "A128734"},
        {"Siti Sarah", "A120945"},
        {"Siti Khadijah", "A154237"},
        {"Syed Azman", "A276456"},
        {"Chong Wei", "A156278"}
    };
    cout<<"Searching Student's Info\n------------------------------\nEnter the name or partial name,\n";
    cout<<"you would like to search for: ";
    getline(cin,searchName);

    searchStudent(searchName, studentArray);
    return 0;
}