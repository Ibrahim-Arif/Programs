#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100][100],i,j,sum=0,n;
    printf("To find sum of left diagonals of a matrix.");
    printf("\n------------------------------------------\n");
    printf("Enter the number of width of matrix:");
    scanf("%d",&n);
    printf("-------------------------------------\n");
    printf("Enter %d values for elements of array:\n",n*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Element-[%d][%d] = ",i,j);
            scanf("%d",&arr1[i][j]);
            if(i==j)
            {
                sum=sum+arr1[i][j];
            }
        }
    }
    printf("\nMatrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nSum of left diagonals: %d",sum);
    printf("\n\n");


    return 0;
}
