#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctors.h"

Doctor* doctorList = NULL;

void doctorMenu() {
    int choice;
    printf("\n--- Doctor Management ---\n");
    printf("1. Add Doctor\n");
    printf("2. View Doctors\n");
    printf("3. Search Doctor\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addDoctor();
            break;
        case 2:
            viewDoctors();
            break;
        case 3:
            searchDoctor();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addDoctor() {
    Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
    printf("Enter doctor ID: ");
    scanf("%d", &newDoctor->id);
    printf("Enter doctor name: ");
    scanf("%s", newDoctor->name);
    printf("Enter doctor specialty: ");
    scanf("%s", newDoctor->specialty);
    newDoctor->next = doctorList;
    doctorList = newDoctor;
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    Doctor* current = doctorList;
    printf("\n--- List of Doctors ---\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Specialty: %s\n", current->id, current->name, current->specialty);
        current = current->next;
    }
}

void searchDoctor() {
    int id;
    printf("Enter doctor ID to search: ");
    scanf("%d", &id);
    Doctor* current = doctorList;
    while (current != NULL) {
        if (current->id == id) {
            printf("Doctor found: %s, Specialty: %s\n", current->name, current->specialty);
            return;
        }
        current = current->next;
    }
    printf("Doctor not found.\n");
}