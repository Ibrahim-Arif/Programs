#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a=1,b=2,c=3;
    float d=4.5;
    printf("1\n");
    printf("  *\n ***\n*****\n ***\n  *");
    printf("\n\n");

    printf("\n");
    printf("**********\n");
    printf("\n*        *");
    printf("\n*        *");
    printf("\n*        *");
    printf("\n*        *");
    printf("\n**********\n\n");

    printf("3\n");
    for(i=1;i<6;i++)
    {
       for(j=1;j<=i;j++)
       {
           printf("*");
       }
       printf("\n");
    }
     printf("\n");
     printf("%d %d %d %5.2f",a,b,c,d);








    return 0;

}
