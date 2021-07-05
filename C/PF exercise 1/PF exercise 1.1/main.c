#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float no1, no2, sum, multi, subt, quot, power, factorial=1, factorail2=1;
    int choice, remain;
    printf("1 for addition.\n");
    printf("2 for difference.\n");
    printf("3 for product.\n");
    printf("4 for quotient.\n");
    printf("5 for remainder.\n");
    printf("6 for power.\n");
    printf("7 for factorial.\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    printf("Enter 1st number: ");
    scanf("%f",&no1);
    printf("Enter 2nd number: ");
    scanf("%f",&no2);
    printf("\n");

    if(choice == 1)
    {
        sum = no1 + no2;
        printf("%f+%f= %f",no1,no2,sum);
    }
    else if(choice == 2)
    {
        subt = no1 - no2;
        printf("%f+%f= %f",no1,no2,subt);
    }
    else if(choice == 3)
    {
        multi = no1 * no2;
        printf("%fx%f= %f",no1,no2,multi);
    }
    else if(choice == 4)
    {
        quot = no1 / no2;
        printf("%f/%f= %f",no1,no2,quot);
    }
    else if(choice == 5)
    {
        int a=no1;
        int b=no2;
        remain = a % b;
        printf("%d%c%d= %d",a,37,b,remain);
    }
    else if(choice == 6)
    {
        power = pow(no1,no2);
        printf("%f^%f= %f",no1,no2,power);
    }
    else if(choice == 7)
    {
        for(int i=no1;i>0;i--)
        {
             factorial= factorial * i;
        }
        printf("%f!= %f\n",no1,factorial);

        for(int j=no2;j>0;j--)
        {
            factorail2 = factorail2 *j;
        }
        printf("%f! = %f",no2,factorail2);
    }
    else
        printf("Invalid choice.\n\n");

    printf("\n\n");
    system("pause");

    return 0;
}
