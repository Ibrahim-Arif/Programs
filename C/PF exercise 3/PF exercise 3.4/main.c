#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no, i, count=100,a,z=0;
    printf("Enter a 4-digit no: ");
    scanf("%d",&no);

    for(i=1;i<=2;i++)
    {
        a=no / count;
        no=no % count;
        if(z==0)
        {
        printf("hundets: %d    ",a);
        z++;
        }
        if(no>50)
     {

            no=no-50;
            printf("fifties= 1\t");
     }
        else if(z==1)
            printf("tens: %d",a);

        count/=10;
    }
    printf("\n\n");
    return 0;
}
