#include <stdio.h>
#include <stdlib.h>
int find_freq(int arr[], int frequency[], int size);

int main()
{
    int arr[100], frequency[100], size, dupElements, i;
    printf("Input the number of element to be stored in the array: ");
    scanf("%d",&size);
    printf("Enter %d elements in the array: \n", size);
    for(i=0;i<size;i++)
    {
        printf("element - %d: ",i);
        scanf("%d",&arr[i]);
        frequency[i] = 1;
    }
    dupElements=find_freq(arr, frequency, size);

    printf("The total number of duplicate element found in the array is: %d",dupElements);

    printf("\n\n");
    return 0;
}

int find_freq(int arr[], int frequency[], int size)
{
    int i, j, dup=0, count;
    for(i=0;i<size;i++)
    {
        count=1;
        for(j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                dup=dup++;
              /*count++;
                frequency[j] = -1;*/
            }
        }
       /* if(frequency[i] != -1)
            frequency[i] = count;
    }
    for(i=0;i<size;i++)
    {
        if(frequency[i] >1)
            dup++;
    }*/
    return dup;
}}

