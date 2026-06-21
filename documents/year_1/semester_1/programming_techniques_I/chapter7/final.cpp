#include <iostream>
#include <string>
#define SIZE 3
using namespace std;

void getSpec(string caption, string *p_data) {
    cout << caption;
    cin >> *p_data;
}

void getSpec(string caption, int *p_data) {
    cout << caption;
    cin >> *p_data;
}

int fastestModel(string *m[], int *hp, int *w) {
    float whp_ratio=0.0, whp_ratio_lowest = 9999;
    int idx = -1;  // Initialize idx to an invalid value
    cout << "Check weight and horsepower ratio: \n";
    for (int i = 0; i < SIZE; i++) {
        whp_ratio = static_cast<float>(w[i]) / hp[i];
        cout << *m[i] << " - " << whp_ratio << "\n";
        if (whp_ratio < whp_ratio_lowest) {
            whp_ratio_lowest = whp_ratio;
            idx = i;
        }
    }
    cout << "\n";
    return idx;
}

int main() {
    string *models[SIZE];
    int *horsepower[SIZE];
    int weight[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        models[i] = new string;
        getSpec("Car's model: ", models[i]);
        horsepower[i] = new int;
        getSpec("Horsepower (hp): ", horsepower[i]);
        getSpec("Weight (Kg): ", &weight[i]);
        cout << "\n";
    }
    
    int idx_fastest = fastestModel(models, *horsepower, weight);
    cout << "Fastest car's model is " << *models[idx_fastest]
         << " with " << *horsepower[idx_fastest] << " horsepower and "
         << weight[idx_fastest] << " kg of weight\n\n";
    
    // delete array data from memory
    for (int i = 0; i < SIZE; i++) {
        delete models[i];
        delete horsepower[i];
    }
    
    return 0;
}
