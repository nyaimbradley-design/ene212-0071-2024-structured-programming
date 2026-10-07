#include <stdio.h>
#include <stdlib.h>

int main()
{
    int marks;

    printf("Enter student marks: ");
    scanf("%d", &marks);

    if (marks < 0 || marks > 100)
    {
        printf("Invalid marks\n");
        return 0;
    }

    switch (marks / 10)
    {
        case 10:
        case 9:
        case 8:
        case 7:
            printf("Grade: A\n");
            break;

        case 6:
            printf("Grade: B\n");
            break;

        case 5:
            printf("Grade: C\n");
            break;

        case 4:
            printf("Grade: D\n");
            break;

        default:
            printf("Fail\n");
    }

    return 0;
}
