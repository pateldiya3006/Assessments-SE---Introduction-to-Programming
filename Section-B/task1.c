#include<stdio.h>

main()
{
    float percentage;

    printf("Enter percentage: ");
    scanf("%f", &percentage);

    if(percentage < 0 || percentage > 100)
    {
        printf("Error: Percentage must be between 0 and 100.");
        return 0;
    }

    if(percentage >= 90)
    {
        printf("Grade: A - Excellent work!");
    }
    else if(percentage >= 75)
    {
        printf("Grade: B - Good work! Keep pushing.");
    }
    else if(percentage >= 60)
    {
        printf("Grade: C - Nice effort! Keep improving.");
    }
    else if(percentage >= 45)
    {
        printf("Grade: D - Keep practicing!");
    }
    else
    {
        printf("Grade: F - Don't give up! Keep working hard.");
    }
}
