#include <stdio.h>
void main()
{
    int n,j,k,l,a=1,u;
    printf("enter the number:");
    scanf("%d",&n);
    u=n+3;
    for(j=1;j<=n;j++)
    {
        for(k=u;k>=1;k--)
        {
            printf(" ");
        }
        for(l=1;l<=j;l++)
        {
            printf("%d ",a++);
        }
        printf("\n");
        u--;
    }
return 0;
}
