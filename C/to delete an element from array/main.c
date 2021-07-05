#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100];
    int n=0,i,pos;
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
    printf("enter the number of element to delete:");
    scanf("%d",&pos);

    for(i=pos;i<n-1;i++)
    {
        arr1[i]=arr1[i+1];
    }
    printf("elements after deletion are: ");
    for(i=0;i<n-1;i++)
    {
        printf("%d ",arr1[i]);
    }

    return 0;
}
