#include<stdio.h>

struct Expense
{
    char category[30];
    float amount;
};

main()
{
    struct Expense expenses[10];
    int count = 0;
    int choice;
    int i;
    float total;
    FILE *file;

    while(1)
    {
        printf("\n\nPersonal Expense Logger");
        printf("\n1. Add Expense");
        printf("\n2. View All Expenses");
        printf("\n3. Save & Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(count < 10)
            {
                printf("Enter category: ");
                scanf(" %[^\n]", expenses[count].category);

                printf("Enter amount: ");
                scanf("%f", &expenses[count].amount);

                count++;

                printf("Expense added successfully.");
            }
            else
            {
                printf("Expense limit reached. Maximum 10 expenses allowed.");
            }
        }
        else if(choice == 2)
        {
            if(count == 0)
            {
                printf("No expenses logged.");
            }
            else
            {
                total = 0;

                printf("\nExpense List\n");
                printf("-----------------------------------\n");
                printf("%-20s %-10s\n", "Category", "Amount");
                printf("-----------------------------------\n");

                for(i = 0; i < count; i++)
                {
                    printf("%-20s %.2f\n",
                           expenses[i].category,
                           expenses[i].amount);

                    total = total + expenses[i].amount;
                }

                printf("-----------------------------------\n");
                printf("Running Total = %.2f\n", total);
            }
        }
        else if(choice == 3)
        {
            file = fopen("expenses.txt", "w");

            if(file == NULL)
            {
                printf("Error opening file.");
            }
            else
            {
                for(i = 0; i < count; i++)
                {
                    fprintf(file, "%s,%.2f\n",
                            expenses[i].category,
                            expenses[i].amount);
                }

                fclose(file);

                printf("Expenses saved successfully.");
                printf("\nExiting Personal Expense Logger...");
                break;
            }
        }
        else
        {
            printf("Invalid choice.");
        }
    }
}
