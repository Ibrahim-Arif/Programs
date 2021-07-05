#include <stdio.h>
#include <stdlib.h>
#define index 10

void getArray(int arr[])
{
    int i;
    for(i=0;i<index-5;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=5;i<10;i++)
    {
        arr[i]=0;
    }
    /*for(i=0;i<index;i++)
        printf("%d\n",arr[i]);*/
}

void FindEven(int arr[])
{
    int i, count=0;
    for(i=0;i<index;i++)
    {
        if(arr[i]%2==0)
            count++;
    }
    printf("no of even numbers: %d",count);
}

void ModifyArray(int arr[])
{
    int i;
    printf("\nArray after multiple of 4\n");
    printf("------------------------------\n");
    for(i=0;i<index; )
    {
        arr[i]=arr[i]*4;
        printf("\n%d element: %d\n",++i,arr[i]);
    }
}

int FindMax(int arr[])
{
    int i, max, max_index;
    max=arr[0];
    for(i=0;i<index;i++)
    {
        if(arr[i]>=max)
            {
                max=arr[i];
                max_index=i;
            }
    }
    //printf("Largest: %d",max);
    return max_index;
}

int main()
{
    int arr[index], max_index;
    getArray(arr);
    FindEven(arr);
    ModifyArray(arr);
    max_index=FindMax(arr);
    printf("\nLargest: %d",arr[max_index]/4);
    return 0;
}
