#include<stdio.h>

main()
{
    float studyHours[7];
    float total = 0;
    float average;
    float highest;
    int highestDay = 0;
    int i, j, hours;

    for(i = 0; i < 7; i++)
    {
        while(1)
        {
            printf("Enter study hours for Day %d: ", i + 1);
            scanf("%f", &studyHours[i]);

            if(studyHours[i] >= 0 && studyHours[i] <= 24)
            {
                break;
            }

            printf("Invalid input. Enter hours between 0 and 24.\n");
        }

        total = total + studyHours[i];
    }

    highest = studyHours[0];

    for(i = 1; i < 7; i++)
    {
        if(studyHours[i] > highest)
        {
            highest = studyHours[i];
            highestDay = i;
        }
    }

    average = total / 7;

    printf("\nWeekly Performance Summary\n");
    printf("Weekly Total = %.2f hours\n", total);
    printf("Daily Average = %.2f hours\n", average);
    printf("Highest Study Hours = Day %d (%.2f hours)\n", highestDay + 1, highest);

    printf("\nStudy Hours Bar:\n");

    for(i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);

        hours = (int)studyHours[i];

        for(j = 0; j < hours; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}
