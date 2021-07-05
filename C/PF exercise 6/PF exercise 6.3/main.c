#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstValue, secondValue;
    int *firstPtr=0, *secondPtr=0;
    int *temp=0;
    firstPtr = &firstValue;
    secondPtr = &secondValue;

    printf("Enter 1st value: ");
    scanf("%d",&firstValue);
    printf("Enter 2nd value: ");
    scanf("%d",&secondValue);

    printf("\noriginal values are:\n");
    printf("1st value=%d\n",firstValue);
    printf("2nd value=%d\n",secondValue);

    printf("\nAfter Swapping values are:\n");
    temp=firstPtr;
    firstPtr=secondPtr;
    secondPtr=temp;
    printf("1st value=%d\n",*firstPtr);
    printf("2nd value=%d\n",*secondPtr);

    printf("\n\n");
    return 0;
}
