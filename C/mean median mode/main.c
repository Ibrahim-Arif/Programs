#include <stdio.h>
#include <stdlib.h>
#define index 15

float find_mean(int arr[])
{
    int total=0;
    float mean=0;
    for(int i=0;i<index;i++)
    {
        total+=arr[i];
    }
    mean=(float)total/(float)index;
    return mean;
}

int find_median(int arr[])
{
    int i,temp,mid;
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
        printf("\nAfter sorting\n");
        for(i=0;i<index;i++)
        {
            printf("%d ",arr[i]);
        }
        mid=(index-1)/2;
        printf("Median: %d",arr[mid]);
}


int main()
{
    int arr[15]={1,2,3,7,5,3,2,45,2,34,56,4,267,8,2};
    float mean,median;

    mean=find_mean(arr);
    printf("Mean: %.2f",mean);

    median=find_median(arr);


    return 0;
}
