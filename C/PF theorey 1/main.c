#include <stdio.h>
#include <stdlib.h>

int main()
{
    int YOS, salary;
    char gender, qualification;
    printf("M for Male.\n");
    printf("F for Female.\n");
    printf("P for Post-Graduate.\n");
    printf("G for Graduate.\n\n");
    printf("Enter Gender: ");
    scanf("%c",&gender);

    if(gender == 'M')
    {
        printf("Enter Years of Service: ");
        scanf("%d",&YOS);
        printf("Enter Qualification: ");
        fflush(stdin);
        scanf("%c",&qualification);

        if(YOS >= 10  &&  qualification == 'P')
            printf("Salary: 15,000");
        else if(YOS >= 10  &&  qualification == 'G')
            printf("Salary: 10,000");
        else if(YOS < 10  &&  qualification == 'P')
            printf("Salary: 10,000");
        else if(YOS < 10  &&  qualification == 'G')
            printf("Salary: 7,000");
    }

    if(gender == 'F')
    {
        printf("Enter Years of Service: ");
        scanf("%d",&YOS);
        printf("Enter Qualification: ");
        fflush(stdin);
        scanf("%c",&qualification);

        if(YOS >= 10  &&  qualification == 'P')
            printf("Salary: 12,000");
        else if(YOS >= 10  &&  qualification == 'G')
            printf("Salary: 9,000");
        else if(YOS < 10  &&  qualification == 'P')
            printf("Salary: 10,000");
        else if(YOS < 10  &&  qualification == 'G')
            printf("Salary: 6,000");
    }
    printf("\n\n");
    system("pause");
    return 0;
}
