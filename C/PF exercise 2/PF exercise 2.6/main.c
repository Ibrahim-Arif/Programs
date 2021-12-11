#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=1,max=0,min=100000000;
    /*printf("enter a num:");
    scanf("%d",&max);*/

    while(i<=5)
    {
        printf("enter next num:");
        scanf("%d",&n);

        if(max>n)
            max=max;
        else
            max=n;

        if(min<n)
            min=min;
        else
            min=n;

        i++;
    }
        printf("the max num is:%d",max);
        printf("\nthe min num is:%d\n\n",min);

    return 0;
}
