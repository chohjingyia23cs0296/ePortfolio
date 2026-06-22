#include <iostream>
#include <array>
#include <string>
using namespace std;

class Stack {
private:
    int top;
    static const int MAX = 5;
    string arr[MAX]; 

public:
    Stack() { 
        top = -1; 
    }

    bool push(const string& action) {
        if (isFull()) {
            cout << "The stack is full" << endl;
            return false;
        } else {
            arr[++top] = action;
            return true;
        }
    }

    string pop() {
        if (isEmpty()) {
            cout << "The stack is empty" << endl;
            return "";
        } else {
            return arr[top--];
        }
    }

    string stackTop() const {
        if (isEmpty()) {
            return "";
        } else {
            return arr[top];
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    bool isFull() const {
        return (top == MAX - 1);
    }

    bool isEmpty() const {
        return (top < 0);
    }
};

void performUndo(Stack& undoStack, Stack& redoStack, string& text) {
    if (undoStack.isEmpty()) {
        cout << "Nothing to undo." << endl;
        return;
    }

    string currentText = text;

    string lastAction = undoStack.pop();

    if (redoStack.isFull()) {
        redoStack.pop();  
    }
    redoStack.push(currentText);  

    text = lastAction;
    cout << "Undo is performed. Current text: " << text << endl;
}

void performRedo(Stack& redoStack, Stack& undoStack, string& text) {
    if (redoStack.isEmpty()) {
        cout << "Nothing to redo." << endl;
        return;
    }

    string currentText = text;

    string lastRedoAction = redoStack.pop();

    if (undoStack.isFull()) {
        undoStack.pop();  
    }
    undoStack.push(currentText); 

    text = lastRedoAction;
    cout << "Redo is performed. Current text: " << text << endl;
}

int main() {
    Stack undoStack, redoStack;
    string text = ""; 
    int textChangesCount = 0; 

    cout << "********* Text Editor with Undo/Redo *********" << endl;
    cout << "Maximum changes allowed: 5" << endl;
    cout << "----------------------------------------------" << endl;

    int choice;
    while (true) {
        cout << "\nCurrent text: " << text << endl;
        cout << "Changes made: " << textChangesCount << "/5" << endl;
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Text" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Display Current Text" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            if (textChangesCount >= 5) {
                cout << "Text addition limit reached. Please undo some changes first." << endl;
                break;
            }

            string newText;
            cout << "Enter text to add: ";
            cin.ignore(); 
            getline(cin, newText);

            if (newText.empty()) {
                cout << "No text entered. Operation cancelled." << endl;
                break;
            }

            undoStack.push(text);
            text += newText;
            redoStack = Stack();  // Clear redo stack after a new action
            textChangesCount++;
            cout << "Text added successfully!" << endl;
            break;
        }
        case 2:
            if (textChangesCount > 0) {
                performUndo(undoStack, redoStack, text);
                textChangesCount--;
            } else {
                cout << "Nothing to undo." << endl;
            }
            break;

        case 3:
            if (!redoStack.isEmpty()) {
                performRedo(redoStack, undoStack, text);
                textChangesCount++;
            } else {
                cout << "Nothing to redo." << endl;
            }
            break;

        case 4:
            if (text.empty()) {
                cout << "Current text is empty." << endl;
            } else {
                cout << "Current text: " << text << endl;
            }
            break;

        case 5:
            cout << "Thank you for using the Text Editor!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
        
        cout << "----------------------------------------------" << endl;
    }

    return 0;
}