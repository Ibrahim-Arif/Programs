#include <stdio.h>
#include <stdlib.h>

int series(int);

int main()
{
    int n,total;
    printf("To find the sum of series 1!/1+2!/2+3!/3+4!/4+5!/5\n");
    printf("---------------------------------------------------");
    printf("\nEnter the ending number of series:");
    scanf("%d",&n);
    total=series(n);
    printf("total=%d",total);
    printf("\n\n");
    //return 0;
}
int series(int a)
{
    int sum=0,i,j,fac=1;
    for(i=1;i<=a;i++)
    {
        for(j=i;j>=1;j--)
        {
            fac=fac*j;
        }
        sum=sum+(fac/i);
        return sum;

    }
}
