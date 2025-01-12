#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char disease[50];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        printf("Enter Patient ID: ");
        scanf("%d", &patients[patientCount].id);
        printf("Enter Patient Name: ");
        scanf(" %s", patients[patientCount].name);
        printf("Enter Age: ");
        scanf("%d", &patients[patientCount].age);
        printf("Enter Disease: ");
        scanf(" %s", patients[patientCount].disease);
        patientCount++;
        printf("Patient added successfully!\n");
    } else {
        printf("Patient limit reached!\n");
    }
}

void displayPatients() {
    if (patientCount == 0) {
        printf("No patients to display.\n");
        return;
    }
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].disease);
    }
}

void searchPatient() {
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Patient Found: ID: %d | Name: %s | Age: %d | Disease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].disease);
            return;
        }
    }
    printf("Patient not found!\n");
}

void deletePatient() {
    int id;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n2. Display Patients\n3. Search Patient\n4. Delete Patient\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: printf("Exiting system...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
