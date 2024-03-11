#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an account
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[10]; // Array to store accounts (for simplicity, using a fixed size array)

int numAccounts = 0; // Variable to keep track of the number of accounts

void displayMenu() {
    printf("\nBanking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Display All Accounts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void createAccount() {
    if (numAccounts < 10) {
        Account newAccount;
        newAccount.accountNumber = numAccounts + 1;

        printf("Enter account holder's name: ");
        scanf("%s", newAccount.name);

        printf("Enter initial balance: ");
        scanf("%f", &newAccount.balance);

        accounts[numAccounts] = newAccount;
        numAccounts++;

        printf("Account created successfully!\n");
    } else {
        printf("Maximum accounts limit reached!\n");
    }
}

void deposit() {
    int accountNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNum);

    if (accountNum <= numAccounts && accountNum > 0) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);

        accounts[accountNum - 1].balance += amount;
        printf("Deposit successful! Current balance: %.2f\n", accounts[accountNum - 1].balance);
    } else {
        printf("Invalid account number!\n");
    }
}

void withdraw() {
    int accountNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNum);

    if (accountNum <= numAccounts && accountNum > 0) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);

        if (amount <= accounts[accountNum - 1].balance) {
            accounts[accountNum - 1].balance -= amount;
            printf("Withdrawal successful! Current balance: %.2f\n", accounts[accountNum - 1].balance);
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Invalid account number!\n");
    }
}

void displayAllAccounts() {
    printf("\nAll Accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAllAccounts();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
