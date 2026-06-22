#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <cstring>

class InventoryItem {
private:
    char* description;
    double costs;
    int units;

public: 
    // Constructor
    InventoryItem(const char* desc, double c, int u) {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
        costs = c;
        units = u;
    }

    // Destructor
    ~InventoryItem() {
        delete[] description;
    }
    
    // Getter functions
    const char* getDescription() const {
        return description;
    }

    double getCost() const {
        return costs;
    }

    int getUnits() const {
        return units;
    } 
};

#endif
