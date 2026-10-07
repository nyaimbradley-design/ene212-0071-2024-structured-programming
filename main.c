#include <stdio.h>
#include <stdlib.h>

int main()
{
    int correctPin = 1234;
    int enteredPin;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == correctPin)
        {
            printf("Access Granted\n");
            return 0;
        }

        attempts++;

        if (attempts < 3)
        {
            printf("Incorrect PIN. Try again.\n");
        }
    }

    printf("Access Denied. Maximum attempts reached.\n");

    return 0;
}
