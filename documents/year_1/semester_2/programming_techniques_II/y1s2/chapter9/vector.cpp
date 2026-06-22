#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare a vector to hold int elements
    vector<int> scores;

    // Declare a vector with initial size 30
    vector<int> scores_with_size(30);

    // Declare a vector and initialize all elements to 0
    vector<int> scores_with_initial_value(30, 0);

    // Declare a vector initialized to size and contents of another vector
    vector<int> finals(scores_with_initial_value);

    // Adding Elements to a Vector
    scores.push_back(75);

    // Use size member function to determine size of a vector
    size_t howbig = scores.size();
    cout << "Size of scores: " << howbig << endl;

    // Removing Vector Elements
    // Use pop_back member function to remove last element from vector
    scores.pop_back();

    // To remove all contents of vector, use clear member function
    scores.clear();

    // To determine if vector is empty, use empty member function
    if (scores.empty()) {
        cout << "Scores vector is empty" << endl;
    } else {
        cout << "Scores vector is not empty" << endl;
    }

    return 0;
}
