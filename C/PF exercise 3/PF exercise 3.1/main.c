#include <stdio.h>
#include <stdlib.h>

int main()
{
    int km, count=0;
    float liter, liter_km, sum_liter_km;
    while(liter!=-1)
    {
    printf("Enter the liters used (-1 to end): ");
    scanf("%f",&liter);
    if(liter==-1)
        break;
    printf("Enter the kilometers driven: ");
    scanf("%d",&km);

    liter_km = (liter/km) * 100;
    sum_liter_km = sum_liter_km + liter_km;
    printf("The liters/100 KM for this tank was : %.1f\n\n",liter_km);
    count++;

    }
    float average = sum_liter_km/count;
    printf("\nThe overall average consumption was: %.1f\n\n",average);

    return 0;
}
