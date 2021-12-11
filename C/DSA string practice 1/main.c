#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("%d", sizeof(int));
    int n=0;
    printf("Enter length: ");
    scanf("%d",&n);

    int *ptr = (int*)malloc(n * sizeof(int));
    //int *ptr = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d",ptr+i);
    }
    for(int i=0; i<n; i++){
        printf("%d ",*(ptr+i));
    }

    printf("\nEnter next five values: \n");
    ptr = (int*) realloc(ptr, n+5);

    for(int i=n; i<n+5; i++){
        scanf("%d",ptr+i);
    }
    for(int i=0; i<n+5; i++){
        printf("%d ",*(ptr+i));
    }
    free(ptr);
    ptr=NULL;

    return 0;
}
