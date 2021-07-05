#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10] = { 2,6,-4,8,10,-12,14,16,18,20 };
    int i, *ptr = arr;

    printf("1. printing array using array[i] notation.\n");
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);

    printf("\n\n2. printing array using ptr[i] notation.\n");
    for(i=0;i<10;i++)
        printf("%d ", ptr[i]);

    printf("\n\n3. printing array using *(array+i) notation. \n");
    for(i=0;i<10;i++)
        printf("%d ", *(arr+i));

    printf("\n\n4. printing array using *(ptr+i) notation. \n");
    for(i=0;i<10;i++)
        printf("%d ",*(ptr+i));

    printf("\n\n5. printing array using *ptr notation. \n");
    for(i=0;i<10;i++)
    {
        printf("%d ",*ptr);
        ptr++;
    }

    printf("\n\n");
    return 0;
}
