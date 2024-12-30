#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include module headers
#include "patients.h"
#include "doctors.h"
#include "appointments.h"
#include "billing.h"
#include "inventory.h"

// Function prototypes for main menu
void mainMenu();

int main() {
    printf("Welcome to the Hospital Management System\n");
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Manage Patients\n");
        printf("2. Manage Doctors\n");
        printf("3. Schedule Appointments\n");
        printf("4. Manage Billing\n");
        printf("5. Inventory Management\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                patientMenu();
                break;
            case 2:
                doctorMenu();
                break;
            case 3:
                appointmentMenu();
                break;
            case 4:
                billingMenu();
                break;
            case 5:
                inventoryMenu();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);
}