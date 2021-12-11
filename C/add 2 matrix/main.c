#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100][100], arr2[100][100], arr3[100][100];
    int n,i,j;
    printf("To add two matrix of same order.\n");
    printf("__________________________________\n");
    printf("Enter square matrix width:");
    scanf("%d",&n);
    printf("___________________________\n");
    printf("Enter numbers of 1st matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("element-[%d],[%d]= ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");
    printf("Enter numbers of 2nd matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("element-[%d],[%d]= ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\nElements in 1st array are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n\nElements in 2nd array are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",arr2[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("\n\nAfter addition now array is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",arr3[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
