#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOOKS 100

// Book structure
typedef struct {
    char name[100];
    char author[100];
    int quantity;
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

// Add a book to the library
void addBook() {
    printf("Enter book name: ");
    scanf("%s", books[bookCount].name);
    printf("Enter author: ");
    scanf("%s", books[bookCount].author);
    printf("Enter quantity: ");
    scanf("%d", &books[bookCount].quantity);
    bookCount++;
    printf("Book added successfully!\n");
}

// Search book by name or author
void searchBook() {
    char query[100];
    printf("Enter book name or author to search: ");
    scanf("%s", query);

    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].name, query) || strstr(books[i].author, query)) {
            printf("%s by %s, Quantity: %d\n",
                   books[i].name, books[i].author, books[i].quantity);
        }
    }
}

// Borrow a book
void borrowBook() {
    char bookName[100];
    printf("Enter book name to borrow: ");
    scanf("%s", bookName);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].name, bookName) == 0 && books[i].quantity > 0) {
            books[i].quantity--;
            printf("Book borrowed successfully!\n");
            return;
        }
    }
    printf("Book not available.\n");
}

// Return a book
void returnBook() {
    char bookName[100];
    printf("Enter book name to return: ");
    scanf("%s", bookName);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].name, bookName) == 0) {
            books[i].quantity++;
            printf("Book returned successfully!\n");
            return;
        }
    }
    printf("No such book found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Search Book\n3. Borrow Book\n4. Return Book\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
