#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amount, i;
    float interest=0.05;

    printf("Enter the amount of investment: ");
    scanf("%d",&amount);
    printf("\n");
    printf("Year\t\t\t\tAmount on deposit\n");

    for(i=1;i<11;i++)
    {
        amount = amount + (amount*interest);
        printf(" %d\t\t\t\t\t%d\n",i,amount);
    }
    return 0;
}
