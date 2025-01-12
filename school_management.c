#include <stdio.h>
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter Student Name: ");
    scanf(" %s", students[studentCount].name);
    printf("Enter GPA: ");
    scanf("%f", &students[studentCount].gpa);
    studentCount++;
    printf("Student added!\n");
}

void displayStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
