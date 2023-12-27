#include <iostream>
#include <list>
#include <string>

using namespace std;

// Class to represent an item in the inventory
class Item {
public:
    string code;
    string name;
    int quantity;
    double price;
    
    Item(string code, string name, int quantity, double price) {
        this->code = code;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
    
    // Function to display item details
    void display() {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }
};

// Function to search for an item in the inventory by code or name
list<Item>::iterator search(list<Item>& inventory, string query) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->code == query || it->name == query) {
            return it;
        }
    }
    return inventory.end(); // Item not found
}

// Function to display the inventory
void displayInventory(list<Item>& inventory) {
    cout << "Inventory:\n";
    for (auto& item : inventory) {
        item.display();
        cout << endl;
    }
}

int main() {
    list<Item> inventory;
    inventory.push_back(Item("001", "Pen", 50, 5.0));
    inventory.push_back(Item("002", "Notebook", 20, 15.0));
    inventory.push_back(Item("003", "Eraser", 30, 2.0));
    
    while (true) {
        cout << "Menu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Display inventory\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            string query;
            cout << "Enter item code or name to search: ";
            cin >> query;
            
            auto it = search(inventory, query);
            if (it != inventory.end()) {
                // Item found
                it->display();
                cout << "Enter quantity to purchase: ";
                int quantity;
                cin >> quantity;
                
                if (quantity <= it->quantity) {
                    // Sufficient quantity in stock
                    double cost = quantity * it->price;
                    cout << "Total cost: " << cost << endl;
                    
                    // Update inventory
                    it->quantity -= quantity;
                    cout << "Item updated in inventory.\n";
                } else {
                    // Insufficient quantity in stock
                    cout << "Required item's quantity is not in stock.\n";
                }
            } else {
                // Item not found
                cout << "Requested item is not available.\n";
            }
        } else if (choice == 2) {
            displayInventory(inventory);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    
    return 0;
}
