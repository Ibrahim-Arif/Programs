#include <stdio.h>
#include <stdlib.h>
#define index 2
void inputarray(int arr[][index])
{
    int row, column;
    for(row=0;row<index;row++)
    {
        for(column=0;column<index;column++)
        {
            printf("Enter [%d][%d] element: ",row,column);
            scanf("%d",&arr[row][column]);
        }
    }
}

void printarray(int arr[][index])
{
    int row, column;
    for(row=0;row<index;row++)
    {
        for(column=0;column<index;column++)
        {
            printf("%d\t",arr[row][column]);
        }
    printf("\n");
    }
}

void multiplyarray(int arr1[][index], int arr2[][index], int arr3[][index])
{
    int row, column,r=0, c=0, sum=0;
    for(row=0;row<index;row++)
    {
        for(column=0;column<index;column++)
        {
            r=row;
            c=column;
            sum = ( arr1[r][c] * arr2[c][r] ) + ( arr1[r][++c] * arr2[++c][r] );
            arr3[row][column] = sum;
        }
    }
}

int main()
{
    int arr1[index][index], arr2[index][index], arr3[index][index];
    printf("---1st array---\n");
    inputarray(arr1);
    printf("\n---2nd array---\n");
    inputarray(arr2);
    printf("\n-1st array output-\n");
    printarray(arr1);
    printf("\n-2nd array output-\n");
    printarray(arr2);
    multiplyarray(arr1, arr2, arr3);
    printf("\n");
    printarray(arr3);

    return 0;
}
