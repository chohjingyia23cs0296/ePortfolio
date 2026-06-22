#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Set {
private:
    T* items;         
    int count;         
    int capacity;      

    void resize() {
        capacity *= 2;
        T* newItems = new T[capacity];
        for (int i = 0; i < count; ++i) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }

public:

    Set() : count(0), capacity(10) {
        items = new T[capacity];
    }

    ~Set() {
        delete[] items;
    }


    void add(const T& item) {
        for (int i = 0; i < count; ++i) {
            if (items[i] == item) {
                return; 
            }
        }

        if (count == capacity) {
            resize();
        }

        items[count++] = item;
    }

    int getItemCount() const {
        return count;
    }

    T* getItemsArray() const {
        T* array = new T[count];
        for (int i = 0; i < count; ++i) {
            array[i] = items[i];
        }
        return array;
    }
};

int main() {

    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);

    cout << "Integer set contains " << intSet.getItemCount() << " items." << endl;
    int* intArray = intSet.getItemsArray();
    for (int i = 0; i < intSet.getItemCount(); ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    delete[] intArray;

    Set<string> stringSet;
    stringSet.add("apple");
    stringSet.add("banana");
    stringSet.add("cherry");

    cout << "String set contains " << stringSet.getItemCount() << " items." << endl;
    string* strArray = stringSet.getItemsArray();
    for (int i = 0; i < stringSet.getItemCount(); ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;
    delete[] strArray;

    return 0;
}
