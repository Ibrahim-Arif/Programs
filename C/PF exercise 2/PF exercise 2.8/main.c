#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    for(i=1;i<11;i++)
    {
        printf("Enter a number: ");
        scanf("%d",&n);

        if(n%2==0 && n%3==0)
            printf("%d is even as well as Divisible by 3.\n",n);
        else if(n%2==0)
            printf("%d is even.\n",n);
        else if(n%3==0)
            printf("%d is divisible by 3.\n",n);

    }
    return 0;
}
