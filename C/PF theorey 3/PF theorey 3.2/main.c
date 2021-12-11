#include <stdio.h>
#include <stdlib.h>
void find_freq(int arr[], int frequency[], int size);

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
    find_freq(arr, frequency, size);
    printf("\n\n");
    return 0;
}

void find_freq(int arr[], int frequency[], int size)
{
    int i, j, dup=0, count, flag=0;
    int unique[100];
    for(i=0;i<size;i++)
    {
        count=1;
        for(j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                frequency[j] = -1;
            }
        }
        if(frequency[i] != -1)
            frequency[i] = count;

        if(flag==0)
        {
            printf("\nThe unique elements found in the array are: ");
            flag=1;
        }
        if(frequency[i] == 1)
        {
            if(flag==0)
                {
                    printf("\nThe unique elements found in the array are: ");
                    flag=1;
                }
            printf("%d ", arr[i]);
        }
        else
            printf("\nNo unique element found.");
    }
}

