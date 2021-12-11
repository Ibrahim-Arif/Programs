#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,arr1[100][100];
    int count=0;
    printf("To check matrix is identity matrix.");
    printf("\n__________________________\n");
    printf("Enter no. of rows and column:");
    scanf("%d",&n);
    printf("Enter %d values to store in matrix\n",n*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Element- %dx%d= ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",arr1[i][j]);

        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                if(arr1[i][j]==1)
                {
                    count++;
                }
            }
            else
            {
                if(arr1[i][j]==0)
                {
                    count++;
                }
            }
        }
    }
    if(count==n*n)
    {
        printf("\nmatrix is identity.\n\n");
    }
    else
        printf("\nMatrix is not identity.\n\n");

    system("pause");



    return 0;
}
