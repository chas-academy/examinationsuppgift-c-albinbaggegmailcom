#include <stdio.h>
#include <ctype.h>

int find_best_student(float student_averages[])
{
    float highest_average = 0.0;
    int best_student;

    for (int i = 0; i < 5; i++)
    {
        if (student_averages[i] > highest_average)
        {
            highest_average = student_averages[i];
            best_student = i;
        }
    }

    return best_student;
}

float calculate_total_average(float student_averages[])
{
    float added_averages = 0.0;

    for (int i = 0; i < 5; i++)
    {
        added_averages += student_averages[i];
    }
    
    return added_averages / 5.0;
}

int main()
{
    char student_names[5][10];
    float student_averages[5];

    // Input data for all students
    for (int i = 0; i < 5; i++)
    {
        // Input student name
        scanf("%s", student_names[i]);
        student_names[i][0] = toupper(student_names[i][0]);

        int total_points = 0;

        // Input student points
        for (int j = 0; j < 13; j++)
        {
            int points;
            scanf("%d", &points);
            total_points += points;
        }

        // Calculate student average points
        student_averages[i] = total_points / 13.0;
    }

    // Print best student
    int best_student = find_best_student(student_averages);
    printf("%s\n", student_names[best_student]);

    // Determine total average
    float total_average = calculate_total_average(student_averages);

    // Print students under the total average
    for (int i = 0; i < 5; i++)
    {
        if (student_averages[i] < total_average)
        {
            printf("%s\n", student_names[i]);
        }
    }
    
    return 0;
}