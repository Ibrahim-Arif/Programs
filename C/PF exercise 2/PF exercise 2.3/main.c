#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantity, ppu;
    float purchased, discount=0.1, total;

    printf("Enter the quantity of product: ");
    scanf("%d",&quantity);

    printf("Enter the price per unit: ");
    scanf("%d", &ppu);

    purchased = quantity * ppu;

    if(purchased>1000)
    {
        discount = purchased * discount;
        total = purchased - discount;
        printf("Total expenses= %.2f", total);

    }
    else if(purchased<=1000)
    {
        printf("Total expenses= %.2f", purchased);
    }
    printf("\n\n");
    return 0;
}
