#include<stdio.h>

main()
{
    int numbers[10];
    int i, j;
    int max, min, temp;
    int sum = 0;
    float mean;
    float distanceMin, distanceMax;

    printf("Enter exactly 10 integers:\n");

    for(i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);

        while(scanf("%d", &numbers[i]) != 1)
        {
            printf("Invalid input. Please enter an integer: ");
            while(getchar() != '\n');
        }
    }

    max = numbers[0];
    min = numbers[0];

    for(i = 0; i < 10; i++)
    {
        sum = sum + numbers[i];

        if(numbers[i] > max)
            max = numbers[i];

        if(numbers[i] < min)
            min = numbers[i];
    }

    mean = (float)sum / 10;

    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);
    printf("\nMean = %.2f", mean);

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9 - i; j++)
        {
            if(numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");

    for(i = 0; i < 10; i++)
        printf("%d ", numbers[i]);

    distanceMin = mean - min;
    distanceMax = max - mean;

    if(distanceMin < distanceMax)
        printf("\nMean is closer to the minimum.");
    else if(distanceMax < distanceMin)
        printf("\nMean is closer to the maximum.");
    else
        printf("\nMean is exactly midway between the minimum and maximum.");
}
