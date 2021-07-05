#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100];
    int n=0,i;
    printf("To enter a new element into an array\n");
    printf("_____________________________________\n");
    printf("enter the number of elements to be stored in array:");
    scanf("%d",&n);
    printf("____________________________________________________\n");
    printf("Enter %d elements for array",n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("elements-%d = ",i);
        scanf("%d",&arr1[i]);

    }
    printf("Elements in array now are: ");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
    //n=n++;
    printf("\nEnter the number to be enter in array=");
    scanf("%d",&arr1[n]);

    printf("Elements in array now are: ");
    for(i=0;i<=n;i++)
    {
        printf("%d ",arr1[i]);
    }

    return 0;
}
