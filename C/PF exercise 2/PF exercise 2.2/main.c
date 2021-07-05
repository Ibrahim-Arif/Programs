/* This program is prepared by Muhammad Ibrahim Arif on 11/10/2019 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, d, e, sum;
    float percent;

    printf("Enter the marks of 1st subject: ");
    scanf("%d",&a);
    printf("Enter the marks of 2nd subject: ");
    scanf("%d",&b);
    printf("Enter the marks of 3rd subject: ");
    scanf("%d",&c);
    printf("Enter the marks of 4th subject: ");
    scanf("%d",&d);
    printf("Enter the marks of 5th subject: ");
    scanf("%d",&e);

    sum= a+b+c+d+e;
    percent= (sum*100) / 500;

    printf("\nSum= %d\n",sum);
    printf("Percentage= %.2f\n\n",percent);

    if(percent>=90)
    {
        printf("Grade: A\n");
        printf("Letter grade: Excellent.\n");
        printf("GPA: 4.0\n");
    }
    else if(percent>=85)
    {
        printf("Grade: A-\n");
        printf("Letter grade: Excellent.\n");
        printf("GPA: 3.7\n");
    }
    else if(percent>=80)
    {
        printf("Grade: B+\n");
        printf("Letter grade: Excellent.\n");
        printf("GPA: 3.3\n");
    }
    else if(percent>=75)
    {
        printf("Grade: B\n");
        printf("Letter grade: Good.\n");
        printf("GPA: 3.0\n");
    }
    else if(percent>=70)
    {
        printf("Grade: B-\n");
        printf("Letter grade: Good.\n");
        printf("GPA: 2.7\n");
    }
    else if(percent>=65)
    {
        printf("Grade: C+\n");
        printf("Letter grade: Good.\n");
        printf("GPA: 2.3\n");
    }
    else if(percent>=60)
    {
        printf("Grade: C\n");
        printf("Letter grade: Average.\n");
        printf("GPA: 2.0\n");
    }
    else if(percent>=55)
    {
        printf("Grade: C-\n");
        printf("Letter grade: Average.\n");
        printf("GPA: 1.7\n");
    }
    else if(percent>=50)
    {
        printf("Grade: D\n");
        printf("Letter grade: Average.\n");
        printf("GPA: 1.3\n");
    }
    else if(percent<50)
    {
        printf("Grade: F\n");
        printf("Letter grade: Failing.\n");
        printf("GPA: 0.0\n");
    }



    return 0;
}
