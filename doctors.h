#ifndef DOCTORS_H
#define DOCTORS_H


typedef struct Doctor{
    int id;
    char name[50];
    char specialty[50];
    struct Doctor *next;
} Doctor;

void doctorMenu();
void addDoctor();
void viewDoctors();
void searchDoctor();

#endif