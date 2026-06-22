#include<iostream>
#include<iomanip>
using namespace std;

// Function prototypes
void getScore(double &score);
void calcAverage(double scores[]);
double findLowest(double scores[]);

int main() {
    double scores[5];

    // Get test scores from the user
    for (int i = 0; i < 5; ++i) {
        getScore(scores[i]);
    }

    // Calculate and display the average of the four highest scores
    calcAverage(scores);

    return 0;
}

void getScore(double &score) {
    cout << "Enter a test score: ";
    cin >> score;

    // Validate the input
    while (score < 0 || score > 100) {
        cout << "Invalid input. Test score must be between 0 and 100. Try again: ";
        cin >> score;
    }
}

void calcAverage(double scores[]) {
    // Find the lowest score
    double lowest = findLowest(scores);

    // Calculate the sum of the four highest scores
    double sum = 0.0;
    for (int i = 0; i < 5; ++i) {
        if (scores[i] != lowest) {
            sum += scores[i];
        }
    }

    // Calculate and display the average
    double average = sum / 4.0;
    cout << fixed << setprecision(2);
    cout << "Average of the four best scores: " << average << endl;
}

double findLowest(double scores[]) {
    double lowest = scores[0];
    for (int i = 1; i < 5; ++i) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}
