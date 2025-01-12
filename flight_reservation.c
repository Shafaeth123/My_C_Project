#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TICKETS 100

// Structure for flight ticket
typedef struct {
    int ticketID;
    char name[100];
    char contact[20];
    char gender;
    char email[100];
    char source[50];
    char destination[50];
    char flightType[20];
    char date[20];
    int price;
    int isBooked;
} Ticket;

Ticket tickets[MAX_TICKETS];
int ticketCount = 0;

// Function to book a flight
void bookFlight() {
    Ticket t;
    t.ticketID = ticketCount + 1;
    printf("Enter Passenger Name: ");
    scanf("%s", t.name);
    printf("Enter Contact Number: ");
    scanf("%s", t.contact);
    printf("Enter Gender (M/F): ");
    scanf(" %c", &t.gender);
    printf("Enter Email: ");
    scanf("%s", t.email);

    printf("Enter Flight Type (Domestic/International): ");
    scanf("%s", t.flightType);
    printf("Enter Source: ");
    scanf("%s", t.source);
    printf("Enter Destination: ");
    scanf("%s", t.destination);
    printf("Enter Date of Journey (DD/MM/YYYY): ");
    scanf("%s", t.date);

    printf("Ticket Price: 5000 Tk\n");
    t.price = 5000;
    t.isBooked = 1;
    tickets[ticketCount++] = t;
    printf("\nFlight booked successfully! Your Ticket ID: %d\n", t.ticketID);
}

// Function to cancel a flight reservation
void cancelFlight() {
    int ticketID;
    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &ticketID);

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketID == ticketID && tickets[i].isBooked) {
            tickets[i].isBooked = 0;
            printf("Ticket ID %d has been successfully canceled.\n", ticketID);
            return;
        }
    }
    printf("Ticket not found or already canceled.\n");
}

// Function to check ticket information
void checkTicket() {
    int ticketID;
    printf("Enter Ticket ID to check: ");
    scanf("%d", &ticketID);

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketID == ticketID && tickets[i].isBooked) {
            printf("\nTicket Details:\n");
            printf("Name: %s\nContact: %s\nSource: %s\nDestination: %s\nFlight Type: %s\nDate: %s\nPrice: %d Tk\n", 
                   tickets[i].name, tickets[i].contact, tickets[i].source,
                   tickets[i].destination, tickets[i].flightType, tickets[i].date, tickets[i].price);
            return;
        }
    }
    printf("Ticket not found.\n");
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\nFlight Reservation System\n");
        printf("1. Book Flight\n2. Cancel Flight\n3. Check Ticket\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookFlight(); break;
            case 2: cancelFlight(); break;
            case 3: checkTicket(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
