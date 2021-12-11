#include <stdio.h>
#include <stdlib.h>
#define index 17

void assending(int arr[])
{
    int i, temp;
    for(int j=0;j<index;j++)
    {
        for(i=0;i<index;i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int l, int r, int find)
{
    if(r>=1)
    {
        int mid= l+( r-l)/2;

        if(find == arr[mid])
            return mid;
        else if(find > arr[mid])
            return binary_search(arr, mid+1,r, find);
        else if(find < arr[mid])
            return binary_search(arr,l, mid-1,find);
    }
    return -1;
}

int main()
{
    int find;
    int arr[index]={2,5,4,9,7,7,88,45,25,1,23,14,789,145,12,14,2};

    printf("Original array");
    printf("\n----------------\n");
    for(int j=0;j<index;j++)
        printf("%d  ",arr[j]);

    assending(arr);

    printf("\n\nAfter sorting");
    printf("\n--------------\n");
    for(int j=0;j<index;j++)
        printf("%d  ",arr[j]);

    printf("\n____________________________________________________________");
    printf("\n\nEnter number to find: ");
    scanf("%d",&find);

    int result = binary_search(arr, 0, index-1,find);
    (result==-1) ?  printf("Element not found."):
                                printf("Found at %d",result);
    return 0;
}

