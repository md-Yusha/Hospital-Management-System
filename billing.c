#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "billing.h"

// Define the structure for a billing record
typedef struct Bill {
    int patientID;
    float amount;
    char description[100];
    struct Bill* next;
} Bill;

// Global linked list for bills
Bill* billList = NULL;

void billingMenu() {
    int choice;
    printf("\n--- Billing Management ---\n");
    printf("1. Add Bill\n");
    printf("2. View Bills\n");
    printf("3. Search Bill\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addBill();
            break;
        case 2:
            viewBills();
            break;
        case 3:
            searchBill();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addBill() {
    Bill* newBill = (Bill*)malloc(sizeof(Bill));
    printf("Enter patient ID: ");
    scanf("%d", &newBill->patientID);
    printf("Enter bill amount: ");
    scanf("%f", &newBill->amount);
    printf("Enter bill description: ");
    scanf(" %[^\n]s", newBill->description);  // Read until newline
    newBill->next = billList;
    billList = newBill;
    printf("Bill added successfully!\n");
}

void viewBills() {
    Bill* current = billList;
    printf("\n--- List of Bills ---\n");
    while (current != NULL) {
        printf("Patient ID: %d, Amount: %.2f, Description: %s\n", current->patientID, current->amount, current->description);
        current = current->next;
    }
}

void searchBill() {
    int id;
    printf("Enter patient ID to search bill: ");
    scanf("%d", &id);
    Bill* current = billList;
    while (current != NULL) {
        if (current->patientID == id) {
            printf("Bill found: Amount: %.2f, Description: %s\n", current->amount, current->description);
            return;
        }
        current = current->next;
    }
    printf("Bill not found.\n");
}