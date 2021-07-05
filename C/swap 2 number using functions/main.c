#include <stdio.h>
#include <stdlib.h>

void swip(int,int);
void swip(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("\nAfter swap 1st value: %d",a);
    printf("\nAfter swap 2nd value: %d",b);
    return 0;

}
int main()
{
    int one,two;
    printf("To swip he values of two variables into one another.");
    printf("\n----------------------------------------------------\n");
    printf("Enter 1st value:");
    scanf("%d",&one);
    printf("Enter 2nd value:");
    scanf("%d",&two);
    swip(one, two);
    printf("\n\n");

    return 0;

}
