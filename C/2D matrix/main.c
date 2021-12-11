#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[100][100];
    int row,col,i,j;
    printf("store and print a matrix\n");
    printf("___________\n");
    printf("Enter the number of column= ");
    scanf("%d",&col);
    printf("Enter the number of rows= ");
    scanf("%d",&row);
    printf("\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("element-%dx%d = ",i,j);
            scanf("%d",&arr1[i][j]);

        }
    }
    printf("\nmatrix is:\n\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("\t%d ",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");



    return 0;
}
