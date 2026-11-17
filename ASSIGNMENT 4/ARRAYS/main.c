#include <stdio.h>

#define MAX 100
#define BUFFER_SIZE 5

// 1. Array Reverse Display
void reverseArray(void) {
    int a[MAX], n, i;

    printf("Number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nReverse array: ");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n");
}

// 2. Array Sum Calculation
void arraySum(void) {
    int a[MAX], n, i, sum = 0;

    printf("Number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("Sum of all elements: %d\n", sum);
}

// 3. Print Unique Elements
void uniqueElements(void) {
    int a[MAX], n, i, j, count;

    printf("Number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Unique elements: ");

    for (i = 0; i < n; i++) {
        count = 0;

        for (j = 0; j < n; j++)
            if (a[i] == a[j])
                count++;

        if (count == 1)
            printf("%d ", a[i]);
    }

    printf("\n");
}

// 4. Find Maximum and Minimum
void maximumMinimum(void) {
    int a[MAX], n, i, max, min;

    printf("Number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    max = min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}

// 5. Sort Array in Ascending Order
void sortAscending(void) {
    int a[MAX], n, i, j, temp;

    printf("Array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// 6. Insert in Unsorted Array
void insertElement(void) {
    int a[MAX], n, i, value, pos;

    printf("Array size: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) return;

    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Value to insert: ");
    scanf("%d", &value);

    printf("Position (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Current array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = value;

    printf("\nArray after insertion: ");

    for (i = 0; i <= n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// 7. Circular Data Logger
void insertSample(int a[], int value, int *next, int *count) {
    a[*next] = value;
    *next = (*next + 1) % BUFFER_SIZE;

    if (*count < BUFFER_SIZE)
        (*count)++;
}

void printSamples(int a[], int next, int count) {
    int i;
    int start = (next - count + BUFFER_SIZE) % BUFFER_SIZE;

    printf("Samples (oldest to newest): ");

    for (i = 0; i < count; i++)
        printf("%d ", a[(start + i) % BUFFER_SIZE]);

    printf("\n");
}

void circularLogger(void) {
    int buffer[BUFFER_SIZE];
    int next = 0, count = 0, n, i, value;

    printf("How many sensor readings? ");
    scanf("%d", &n);

    if (n < 0) return;

    for (i = 0; i < n; i++) {
        printf("Enter sensor value: ");
        scanf("%d", &value);

        insertSample(buffer, value, &next, &count);
    }

    printSamples(buffer, next, count);
}

// 8. 2D Array Traversal
void twoDArray(void) {
    int a[6][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    int i, j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", a[i][j]);

        printf("\n");
    }
}

// MAIN PROGRAM
int main(void) {
    int choice;

    do {
        printf("\n===== ASSIGNMENT 4: ARRAYS =====\n");
        printf("1. Reverse array\n");
        printf("2. Sum array elements\n");
        printf("3. Print unique elements\n");
        printf("4. Find maximum and minimum\n");
        printf("5. Sort array ascending\n");
        printf("6. Insert into array\n");
        printf("7. Circular data logger\n");
        printf("8. 2D array traversal\n");
        printf("0. Exit\n");

        printf("Choose a task: ");
        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice) {
            case 1:
                reverseArray();
                break;

            case 2:
                arraySum();
                break;

            case 3:
                uniqueElements();
                break;

            case 4:
                maximumMinimum();
                break;

            case 5:
                sortAscending();
                break;

            case 6:
                insertElement();
                break;

            case 7:
                circularLogger();
                break;

            case 8:
                twoDArray();
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice. Select 0 to 8.\n");
        }

    } while (choice != 0);

    return 0;
}
