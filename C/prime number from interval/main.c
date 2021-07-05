#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start,end,i,j,flag=0,a=0;
    printf("Enter starting number: ");
    scanf("%d",&start);
    printf("Enter endiing number: ");
    scanf("%d",&end);

    for(i=start ; i<=end ; i++)
    {
        for(j=i-1 ; j>1 ; j--)
        {
            if(i%j==0)
                {flag=1;}
        }
        if(flag==0)
            {
                if(a==0)
                {
                  printf("\nPrime number= ");
                  a++;
                }
                printf("%d ",i);
            }

        /*else
            {printf("\n%d is not a prime number.\n",i);}*/
        flag=0;
    }
    return 0;
}
