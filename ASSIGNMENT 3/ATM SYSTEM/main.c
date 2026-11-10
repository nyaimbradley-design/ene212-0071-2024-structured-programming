#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float balance = 0;

int login();
void showMenu();
void checkBalance();
void deposit(float amount);
void withdraw(float amount);
void clearInput();

int main() {
    int choice = 0;
    float amount;

    if (login() == 0) {
        printf("Too many failed attempts. Access denied.\n");
        return 0;
    }

    while (choice != 4) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            clearInput();
            choice = 0;
        }

        if (choice == 1) {
            checkBalance();
        }
        else if (choice == 2) {
            printf("Amount: ");
            amount = 0;
            scanf("%f", &amount);
            deposit(amount);
        }
        else if (choice == 3) {
            printf("Amount: ");
            amount = 0;
            scanf("%f", &amount);
            withdraw(amount);
        }
        else if (choice == 4) {
            printf("Goodbye.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

int login() {
    char correctUser[] = "admin";
    int correctPin = 1234;
    char user[20];
    int pin;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter username: ");
        scanf("%19s", user);
        printf("Enter PIN: ");
        if (scanf("%d", &pin) == 1 && pin == correctPin && strcmp(user, correctUser) == 0)
            return 1;
        clearInput();
        attempts++;
        printf("Wrong username or PIN. %d attempt(s) left.\n", 3 - attempts);
    }
    return 0;
}

void showMenu() {
    printf("\n1. Balance Inquiry\n2. Deposit\n3. Withdraw\n4. Exit\nChoice: ");
}

void checkBalance() {
    printf("Balance: %.2f\n", balance);
}

void deposit(float amount) {
    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }
    balance = balance + amount;
    printf("Deposited %.2f\n", amount);
}

void withdraw(float amount) {
    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }
    if (amount > balance) {
        printf("Insufficient funds.\n");
        return;
    }
    balance = balance - amount;
    printf("Withdrew %.2f\n", amount);
}

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
