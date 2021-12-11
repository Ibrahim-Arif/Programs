#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,sum;
    int *pt1, *pt2;
    printf("To add two integers using Pointers.\n");
    printf("__________________________\n");
    printf("Enter 1st number=");
    scanf("%d",&a);
    printf("Enter 2nd number=");
    scanf("%d",&b);
    pt1 = &a;
    pt2 = &b;
    sum = *pt1 + *pt2;
    printf("\nSum:%d",sum);
    printf("\n\n");



    return 0;
}
