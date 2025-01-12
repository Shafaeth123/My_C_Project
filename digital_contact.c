#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define FILENAME "phonebook.txt"

typedef struct {
    char name[50];
    char phone[12];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int totalContacts = 0;

// Validate phone number (11 digits)
int isValidPhone(char *phone) {
    return (strlen(phone) == 11 && strspn(phone, "0123456789") == 11);
}

// Validate email with basic check for common domains
int isValidEmail(char *email) {
    return (strstr(email, "@gmail.com") || strstr(email, "@yahoo.com") || strstr(email, "@outlook.com"));
}

// Add a new contact
void addContact() {
    Contact c;
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);

    do {
        printf("Enter phone number (11 digits): ");
        scanf("%s", c.phone);
    } while (!isValidPhone(c.phone));

    do {
        printf("Enter email: ");
        scanf("%s", c.email);
    } while (!isValidEmail(c.email));

    contacts[totalContacts++] = c;
    printf("Contact added successfully!\n");
}

// Save contacts to file
void saveToFile() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < totalContacts; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(file);
    printf("Contacts saved to file!\n");
}

// Search contact by name or phone
void searchContact() {
    char query[50];
    printf("Enter name or phone to search: ");
    scanf(" %[^\n]", query);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].name, query) == 0 || strcmp(contacts[i].phone, query) == 0) {
            printf("Found: %s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Main function with menu
int main() {
    int choice;
    while (1) {
        printf("\nPhonebook Menu:\n1. Add Contact\n2. Search Contact\n3. Save to File\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: saveToFile(); break;
            case 4: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
