#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appointments.h"

// Define the structure for an appointment
typedef struct Appointment {
    int appointmentID;
    int patientID;
    char date[20];
    char doctor[50];
    struct Appointment* next;
} Appointment;

// Global linked list for appointments
Appointment* appointmentList = NULL;

void appointmentMenu() {
    int choice;
    printf("\n--- Appointment Management ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Search Appointment\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addAppointment();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            searchAppointment();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter appointment ID: ");
    scanf("%d", &newAppointment->appointmentID);
    printf("Enter patient ID: ");
    scanf("%d", &newAppointment->patientID);
    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%s", newAppointment->date);
    printf("Enter doctor's name: ");
    scanf("%s", newAppointment->doctor);
    newAppointment->next = appointmentList;
    appointmentList = newAppointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    Appointment* current = appointmentList;
    printf("\n--- List of Appointments ---\n");
    while (current != NULL) {
        printf("Appointment ID: %d, Patient ID: %d, Date: %s, Doctor: %s\n",
               current->appointmentID, current->patientID, current->date, current->doctor);
        current = current->next;
    }
}

void searchAppointment() {
    int id;
    printf("Enter appointment ID to search: ");
    scanf("%d", &id);
    Appointment* current = appointmentList;
    while (current != NULL) {
        if (current->appointmentID == id) {
            printf("Appointment found: Patient ID: %d, Date: %s, Doctor: %s\n",
                   current->patientID, current->date, current->doctor);
            return;
        }
        current = current->next;
    }
    printf("Appointment not found.\n");
}