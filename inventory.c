#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

// Define the structure for an inventory item
typedef struct InventoryItem {
    int id;
    char name[50];
    int quantity;
    struct InventoryItem* next;
} InventoryItem;

// Global linked list for inventory items
InventoryItem* inventoryList = NULL;

void inventoryMenu() {
    int choice;
    printf("\n--- Inventory Management ---\n");
    printf("1. Add Inventory Item\n");
    printf("2. View Inventory\n");
    printf("3. Search Inventory\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addInventoryItem();
            break;
        case 2:
            viewInventory();
            break;
        case 3:
            searchInventory();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addInventoryItem() {
    InventoryItem* newItem = (InventoryItem*)malloc(sizeof(InventoryItem));
    printf("Enter item ID: ");
    scanf("%d", &newItem->id);
    printf("Enter item name: ");
    scanf("%s", newItem->name);
    printf("Enter quantity: ");
    scanf("%d", &newItem->quantity);
    newItem->next = inventoryList;
    inventoryList = newItem;
    printf("Inventory item added successfully!\n");
}

void viewInventory() {
    InventoryItem* current = inventoryList;
    printf("\n--- Inventory List ---\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d\n", current->id, current->name, current->quantity);
        current = current->next;
    }
}

void searchInventory() {
    int id;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    InventoryItem* current = inventoryList;
    while (current != NULL) {
        if (current->id == id) {
            printf("Item found: %s, Quantity: %d\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Item not found.\n");
}