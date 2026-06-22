#include <iostream>
#include <iomanip>
#include "InventoryItem.h"

using namespace std;

int main() {
    InventoryItem stock("Wrench", 8.75, 20);

    cout << setprecision(2) << fixed << showpoint;
    cout << "Item description: " << stock.getDescription() << endl;
    cout << "Costs: $" << stock.getCost() << endl;
    cout << "Units on hand: " << stock.getUnits() << endl;

    return 0;
}
