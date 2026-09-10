#include<stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s)
{
    if(s->marks >= 90)
    {
        s->grade = 'A';
    }
    else if(s->marks >= 75)
    {
        s->grade = 'B';
    }
    else if(s->marks >= 60)
    {
        s->grade = 'C';
    }
    else if(s->marks >= 45)
    {
        s->grade = 'D';
    }
    else
    {
        s->grade = 'F';
    }
}

void printTopper(struct Student students[], int n)
{
    int i;
    int topper = 0;

    for(i = 1; i < n; i++)
    {
        if(students[i].marks > students[topper].marks)
        {
            topper = i;
        }
    }

    printf("\nTop Performer: %s", students[topper].name);
    printf("\nMarks: %.2f\n", students[topper].marks);
}

main()
{
    struct Student students[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);

        assignGrade(&students[i]);
    }

    printf("\n\nStudent Records\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Roll No", "Marks", "Grade");
    printf("------------------------------------------------\n");

    for(i = 0; i < 3; i++)
    {
        printf("%-20s %-10d %-10.2f %-10c\n",
               students[i].name,
               students[i].rollno,
               students[i].marks,
               students[i].grade);
    }

    printf("------------------------------------------------\n");

    printTopper(students, 3);
}
