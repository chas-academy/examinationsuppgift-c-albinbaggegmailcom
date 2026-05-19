/*
      Grundläggande funktionalitet (20p)
    - 20p Kompilera och köra utan krasch

      Analys: Högst medelpoäng (30p)
    x 15p Logik - Identifiera vilken elev som har högst medelpoäng
    x 15p Format - Namnet skrivs ut korrekt med stor begynnelsebokstav
    
      Analys: Under gruppens snitt (30p)
    x 15p Logik - Räkna ut totala medelvärdet, identifiera vilka elever som ligger under medelvärdet
    x 15p Format - Namnen skrivs ut med stor begynnelsebokstav, skrivs ut i samma ordning som de matades in

    - Video (20p)
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    // Input data
    char student_names[5][10];
    float student_averages[5];

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

        student_averages[i] = total_points / 13.0;
    }
    // debug
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("Student %d = %s\n", i, student_names[i]);
    //     printf("student_averages[%d] = %.2f\n", i, student_averages[i]);
    // }

    // Compare student point averages
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

    // Print best student
    printf("%s\n", student_names[best_student]);
    // debug
    // printf
    // (
    //     "Best: %s, highest_average = %.2f\n", 
    //     student_names[best_student], highest_average
    // );

    // Calculate total average of points
    float added_averages = 0.0;

    for (int i = 0; i < 5; i++)
    {
        added_averages += student_averages[i];
    }
    
    float total_average = added_averages / 5.0;
    // debug
    // printf("total_average = %.2f\n", total_average);

    // Compare students against total average
    for (int i = 0; i < 5; i++)
    {
        if (student_averages[i] < total_average)
        {
            printf("%s\n", student_names[i]);
        }
    }
    
    return 0;
}