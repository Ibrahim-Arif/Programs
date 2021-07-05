#include <stdio.h>
#include <stdlib.h>

int main()
{
    int marks[10], i;
    float aggre, perc, total;
    for(i=0;i<=9;i++)
    {
        printf("Enter %d subject marks:  ",i+1);
        scanf("%d",&marks[i]);
        total+=marks[i];
    }
    aggre=total/10;
    perc=(total*100)/1000;
    printf("\nAggregate: %.2f\n",aggre);
    printf("Percentage: %.1f%c\n\n",perc,37);
    return 0;
}
