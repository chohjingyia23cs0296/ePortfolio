#include<iostream>
using namespace std;
    const int MAX_BOOKS=10;
void displayMainMenu(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount,int &choice);
void addBook(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount);
void displayLibrary(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount);
void searchByTitle(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount);
int main(){
    
    //book information, including titles, authors, and publication years,
    char titles[MAX_BOOKS][50];
    char authors[MAX_BOOKS][50];
    int publication[MAX_BOOKS];
    int choice;
    int bookcount=0;
    do{
        displayMainMenu(titles, authors, publication,bookcount,choice);
    }while (bookcount<MAX_BOOKS&&choice!=4);
    
    return 0;
}
void displayMainMenu(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount,int&choice){
    cout<<"<<<<<<<<Library Management System>>>>>>>>>"<<endl;
    cout<<"========================================"<<endl;
    cout<<"1. Add a Book"<<endl;
    cout<<"2. Display Library"<<endl;
    cout<<"3. Search by Title"<<endl;
    cout<<"4. Quit"<<endl;
    
    cout<<"Enter your choice:";
    cin>>choice;

    cout<<"\n\n";
    switch (choice){
        case 1: addBook(titles, authors, publication,bookcount);
        break;
        case 2: displayLibrary(titles, authors, publication,bookcount);
        break;
        case 3: searchByTitle(titles, authors, publication,bookcount);
        break;
        case 4:cout << "Goodbye!" << endl;
cout << "\n\n";
cout << "---------------------------" << endl;
break;
        default:
        cout<<"Invalid input.Please try again."<<endl;
    }
}
void addBook(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount) {
    if (bookcount < MAX_BOOKS) {
        cout << "Enter book title: ";
        cin.ignore(); // Ignore previous newline character
        cin.getline(titles[bookcount], 50); // Read the entire line, allowing spaces

        cout << "Enter author name: ";
        cin.getline(authors[bookcount], 50);

        cout << "Enter publication year: ";
        cin >> publication[bookcount];

        bookcount++;
        cout<<"Book added successfully!"<<endl;
        cout<<endl;
    } else {
        cout << "Library already full.\n\n";
    }
}

void displayLibrary(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount){
    cout<<"Library Contents: "<<endl;
    cout<<"===================="<<endl;
    for(int i=0;i<bookcount;i++){
        cout<<"Title: "<<titles[i]<<endl;
    cout<<"Author: "<<authors[i]<<endl;
    cout<<"Year: "<<publication[i]<<endl;
    cout<<"\n\n";
    }
}
void searchByTitle(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication[MAX_BOOKS], int &bookcount){
    string searchitem;
    cout<<"Enter the title to search:";
    cin>>searchitem;
    bool found= false;
    for(int i=0;i<bookcount;i++){
        if(searchitem==titles[i]){
           cout<<"Books Found "<<endl;
    cout<<"===================="<<endl;
        found=true;
        cout<<"Title: "<<titles[i]<<endl;
        cout<<"Author: "<<authors[i]<<endl;
        cout<<"Year: "<<publication[i]<<endl; 
        break;
    }
}
if(!found){
    cout<<"Books not found";
}
}