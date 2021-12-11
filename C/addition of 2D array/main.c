#include <stdio.h>
#include <stdlib.h>

void printAmatrix(int arr[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr1[3][3], arr2[3][3], arr3[3][3], arr4[3][3];
    int i, j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter %dx%d element of matrix 1: ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter %dx%d element of matrix 2: ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\n 1st matrix: \n");
    printAmatrix(arr1);
    printf("\n 2nd matrix: \n");
    printAmatrix(arr2);
    printf("\n sum of matrix: \n");
    printAmatrix(arr3);

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            arr4[j][i] = arr3[i][j];
        }
    }
    printf("\ntranspose of matrix: \n");
    printAmatrix(arr4);

    return 0;
}
