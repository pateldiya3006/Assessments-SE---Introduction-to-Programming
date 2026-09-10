#include<stdio.h>

struct StudyLog
{
    char subject[40];
    float hours[7];
};

void showWeeklyReport(struct StudyLog logs[], int n)
{
    int i, j, dots;
    float total, average;

    printf("\n\nWeekly Productivity Report\n");
    printf("============================================\n");

    for(i = 0; i < n; i++)
    {
        total = 0;

        for(j = 0; j < 7; j++)
        {
            total = total + logs[i].hours[j];
        }

        average = total / 7;

        printf("\nSubject: %s", logs[i].subject);
        printf("\nWeekly Total: %.2f hours", total);
        printf("\nDaily Average: %.2f hours\n", average);

        printf("Progress Chart:\n");

        for(j = 0; j < 7; j++)
        {
            printf("Day %d: ", j + 1);

            dots = (int)logs[i].hours[j];

            while(dots > 0)
            {
                printf("*");
                dots--;
            }

            printf("\n");
        }
    }
}

void saveData(struct StudyLog logs[], int n)
{
    FILE *file;
    int i, j;

    file = fopen("productivity_log.txt", "w");

    if(file == NULL)
    {
        printf("Error opening file.");
        return;
    }

    for(i = 0; i < n; i++)
    {
        fprintf(file, "%s", logs[i].subject);

        for(j = 0; j < 7; j++)
        {
            fprintf(file, ",%.2f", logs[i].hours[j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);

    printf("\nData saved successfully to productivity_log.txt");
}

main()
{
    struct StudyLog logs[3] = {
        {"C Programming", {0, 0, 0, 0, 0, 0, 0}},
        {"HTML", {0, 0, 0, 0, 0, 0, 0}},
        {"CSS", {0, 0, 0, 0, 0, 0, 0}}
    };

    int choice;
    int day;
    int i;
    float hours;

    while(1)
    {
        printf("\n\nStudent Productivity Tracker");
        printf("\n1. Log Today's Study Hours");
        printf("\n2. View Weekly Report");
        printf("\n3. Save & Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter day number (1-7): ");
            scanf("%d", &day);

            if(day < 1 || day > 7)
            {
                printf("Invalid day number.");
            }
            else
            {
                for(i = 0; i < 3; i++)
                {
                    printf("Enter study hours for %s: ", logs[i].subject);
                    scanf("%f", &hours);

                    if(hours < 0 || hours > 24)
                    {
                        printf("Invalid hours. Enter value between 0 and 24: ");
                        scanf("%f", &hours);
                    }

                    logs[i].hours[day - 1] = hours;
                }

                printf("Today's study hours saved successfully.");
            }
        }
        else if(choice == 2)
        {
            showWeeklyReport(logs, 3);
        }
        else if(choice == 3)
        {
            saveData(logs, 3);
            printf("\nExiting Student Productivity Tracker...");
            break;
        }
        else
        {
            printf("Invalid choice.");
        }
    }
}
