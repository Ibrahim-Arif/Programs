#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{

    int r,c,n=1,i,j;
    printf("\nEnter the number of Rows:     ");
    scanf("%d",&r);
    printf("Enter the number of columns:  ");
    scanf("%d",&c);
    printf("_________________________________\n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%d\t",n);
            n=n+r;
        }
        printf("\n");
        for(z=1;z<=j;z++)
        {
            if(z==j)
            {
                n=z+1;
            }
        }

    }

}
