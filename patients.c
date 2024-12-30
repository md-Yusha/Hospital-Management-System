#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patients.h"

// Initialize the head of the linked list
Patient* patientList = NULL;

void patientMenu() {
    int choice;
    printf("\n--- Patient Management ---\n");
    printf("1. Add Patient\n");
    printf("2. View Patients\n");
    printf("3. Search Patient\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addPatient() {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    printf("Enter patient ID: ");
    scanf("%d", &newPatient->id);
    printf("Enter patient name: ");
    scanf("%s", newPatient->name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient->age);
    printf("Enter patient gender: ");
    scanf("%s", newPatient->gender);
    newPatient->next = patientList;
    patientList = newPatient;
    printf("Patient added successfully!\n");
}

void viewPatients() {
    Patient* current = patientList;
    printf("\n--- List of Patients ---\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", current->id, current->name, current->age, current->gender);
        current = current->next;
    }
}

void searchPatient() {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    Patient* current = patientList;
    while (current != NULL) {
        if (current->id == id) {
            printf("Patient found: %s, Age: %d, Gender: %s\n", current->name, current->age, current->gender);
            return;
        }
        current = current->next;
    }
    printf("Patient not found.\n");
}