#ifndef PATIENTS_H
#define PATIENTS_H

typedef struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    struct Patient* next;
} Patient;

// Function prototypes
void patientMenu();
void addPatient();
void viewPatients();
void searchPatient();

#endif