#ifndef INVENTORYITEM2_H
#define INVENTORYITEM2_H

#include <cstring>

const int DEFAULT_SIZE = 100;

class InventoryItem {
private:
    char *description; // The item description
    double costs;      // The item cost
    int units;         // Number of units on hand

public:
    // Constructor
    InventoryItem(char* desc, double c, int u) {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
        costs = c;
        units = u;
    }

    // Destructor
    ~InventoryItem() {
        delete[] description;
    }

    // Member function to set description
    void setDescription(char *d) {
        strcpy(description, d);
    }
};

#endif
