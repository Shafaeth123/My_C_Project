#include <stdio.h>
#include <string.h>
#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char holderName[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount < MAX_ACCOUNTS) {
        Account newAccount;
        newAccount.accountNumber = accountCount + 1;
        printf("Enter account holder name: ");
        scanf(" %s", newAccount.holderName);
        printf("Enter initial deposit: ");
        scanf("%f", &newAccount.balance);
        accounts[accountCount++] = newAccount;
        printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
    } else {
        printf("Bank account limit reached!\n");
    }
}

void depositMoney() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum > 0 && accNum <= accountCount) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        accounts[accNum - 1].balance += amount;
        printf("Deposit successful! New balance: %.2f\n", accounts[accNum - 1].balance);
    } else {
        printf("Invalid account number!\n");
    }
}

void withdrawMoney() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum > 0 && accNum <= accountCount) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (accounts[accNum - 1].balance >= amount) {
            accounts[accNum - 1].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", accounts[accNum - 1].balance);
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Invalid account number!\n");
    }
}

void checkBalance() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum > 0 && accNum <= accountCount) {
        printf("Account Holder: %s\nBalance: %.2f\n", accounts[accNum - 1].holderName, accounts[accNum - 1].balance);
    } else {
        printf("Invalid account number!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: printf("Exiting system...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
