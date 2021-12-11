#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1, j=100, k=20, l=2, m=99;

    printf("\n1:)\n");
    while(i<101)
    {
        printf("%d\t",i);
        i++;
    }

    printf("\n\n2:)\n");
    while(j>0)
    {
        printf("%d\t",j);
        j--;
    }

    printf("\n\n3:)\n");
    while(k>1)
    {
        printf("%d\t",k);
        k=k-2;
    }

    printf("\n\n4:)\n");
    while(l<21)
    {
        printf("%d\t",l);
        l=l+3;
    }

    printf("\n\n5:)\n");
    while(m>=0)
    {
        printf("%d\t",m);
        m=m-11;
    }
    printf("\n\n");



    return 0;
}
