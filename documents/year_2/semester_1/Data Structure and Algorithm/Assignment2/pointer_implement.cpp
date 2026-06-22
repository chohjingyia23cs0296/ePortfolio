#include <iostream>
#include <string>
using namespace std;

class nodeStack {
public:
	string data;
	nodeStack* next;
};

class Stack {
private:
	nodeStack* top;
public:
	Stack() { 
		createStack(); 
	}

	void createStack(){
		top = nullptr;
	}

	void push(string newdata) {
		nodeStack* newnode;
		newnode = new nodeStack;
		newnode->data = newdata;
		newnode->next = top;
		top = newnode;
	}

	void pop() {
		if (isEmpty()) {
			return;
		}
		nodeStack* delnode = top;
		top = delnode->next;
		delete delnode;
	}

	bool isEmpty(){
		return (top == nullptr);
	}	

	string stackTop(){
	if (isEmpty()) {
		return "";
	}
		return top->data;
	}

	void display() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return;
	}
	nodeStack* current = top;
	int count = 1;
	while (current != nullptr) {
		cout << count << ". " << current->data << endl;
		current = current->next;
		count++;
	}
}
};

void performUndo(Stack& undoStack, Stack& redoStack, string& currentText) {
	if (!undoStack.isEmpty()) {
		redoStack.push(currentText);
		currentText = undoStack.stackTop();
		undoStack.pop();
		cout << "Undo successful!" << endl;
	}
}

void performRedo(Stack& redoStack, Stack& undoStack, string& currentText) {
	if (!redoStack.isEmpty()) {
		undoStack.push(currentText);
		currentText = redoStack.stackTop();
		redoStack.pop();
		cout << "Redo successful!" << endl;
	}
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
			redoStack = Stack();
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
