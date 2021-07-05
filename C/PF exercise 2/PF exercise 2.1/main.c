/* This program is prepared by Muhammad Ibrahim Arif on 11/10/2019.*/

#include <stdio.h>
#include <stdlib.h>
#define SURCHARGE 0.05

int main()
{
    int units;
    float total, bill, sur;

    printf("Enter number of units:  ");
    scanf("%d",&units);
    printf("Unit consumed:          %d",units);

    if(units<=300)
    {
        printf("\nCost per unit:          Rs 3");
        total= (units * 3);
        printf("\nBill=                   %f", total);
    }
    else
    {
        printf("\nCost per unit:          Rs 3.5");
        printf("\nSurcharge:              %f",SURCHARGE);
        bill = units * 3.5;
        sur = bill * SURCHARGE;
        total = bill + sur;
        printf("\nBill=                   Rs %f",total);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
