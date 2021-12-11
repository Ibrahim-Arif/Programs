#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100];
    int n,i,pos,neww;
    printf("To insert a value in array at any position\n");
    printf("______________________________________________\n");
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
    printf("values in arrays before new insertion are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);

    }

    printf("\n\nEnter number of element where to insert new value:");
    scanf("%d",&pos);
    printf("Enter the new value:");
    scanf("%d",&neww);
    for(i=n;i>=pos;i--)
    {
        arr1[i]=arr1[i-1];
        if(i==pos)
        {
            arr1[i]=neww;
        }
    }
    printf("\nAfter insertion values in array are: ");
    for(i=0;i<=n;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n\n");


    return 0;
}
