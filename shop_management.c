#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100
#define MAX_USERS 5

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

typedef struct {
    char email[50];
    char password[20];
} Admin;

Product products[MAX_PRODUCTS];
Admin admins[MAX_USERS] = {{"admin@shop.com", "admin123"}};
int productCount = 0;

int loginAdmin() {
    char email[50], password[20];
    printf("Enter Email: ");
    scanf("%s", email);
    printf("Enter Password: ");
    scanf("%s", password);
    
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(email, admins[i].email) == 0 && strcmp(password, admins[i].password) == 0) {
            return 1;
        }
    }
    printf("Invalid login!\n");
    return 0;
}

void addProduct() {
    printf("Adding a new product:\n");
    products[productCount].id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter quantity: ");
    scanf("%d", &products[productCount].quantity);
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    printf("Available Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - $%.2f (Quantity: %d)\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void buyProduct() {
    int id, qty;
    displayProducts();
    printf("Enter product ID to buy: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &qty);
    
    if (id > 0 && id <= productCount && products[id-1].quantity >= qty) {
        products[id-1].quantity -= qty;
        printf("Purchase successful! Total: $%.2f\n", products[id-1].price * qty);
    } else {
        printf("Invalid ID or not enough stock!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Admin Login\n2. Customer Mode\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (loginAdmin()) {
                addProduct();
            }
        } else if (choice == 2) {
            buyProduct();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
