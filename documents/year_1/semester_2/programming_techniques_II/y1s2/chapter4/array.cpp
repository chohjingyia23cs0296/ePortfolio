#include<iostream>
#include<iomanip>
#include "InventoryItem.h" // Assuming this header file contains the InventoryItem class definition

using namespace std;

int main() {
    // Creating an array of InventoryItem objects
    InventoryItem inventory[5] = {
        InventoryItem("Hammer", 6.95, 12),
        InventoryItem("Wrench", 8.75, 20),
        InventoryItem("Pliers", 3.75, 10),
        InventoryItem("Ratchet", 7.95, 14),
        InventoryItem("Screwdriver", 2.5, 22)
    };

    // Output formatting
    cout << setw(14) << "Inventory Item "
         << setw(8) << "Costs" << setw(8)
         << setw(16) << "Units On Hands\n";
    cout << "-------------------------------\n";

    // Outputting the inventory items
    for (int i = 0; i < 5; i++) {
        cout << setw(14) << inventory[i].getDescription();
        cout << setw(8) << inventory[i].getCost();
        cout << setw(7) << inventory[i].getUnits() << endl;
    }

    return 0;
}
