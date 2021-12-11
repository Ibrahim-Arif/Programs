#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=300, *mPtr=0;
    float fx=300.6059, *fxPtr=0;
    char cht = 'z', *chrPtr=0;
    mPtr = &m;
    fxPtr = &fx;
    chrPtr = &cht;

    printf("Using & pointer");
    printf("\n-----------------------\n");
    printf("address of m= %i",&m);
    printf("\naddress of fx= %i",&fx);
    printf("\naddress of cht= %i\n",&cht);

    printf("\nUsing & and * pointer");
    printf("\n------------------------\n");
    printf("values at address of m= %d",*&m);
    printf("\nvalues at address of fx= %f",*&fx);
    printf("\nvalues at address of cht= %c\n",*&cht);

    printf("\nUsing only pointers variable");
    printf("\n--------------------------\n");
    printf("address of m= %i",mPtr);
    printf("\naddress of fx= %i",fxPtr);
    printf("\naddress of cht= %i\n",chrPtr);

    printf("\nUsing only pointer operator");
    printf("\n------------------------\n");
    printf("values at address of m= %d",*mPtr);
    printf("\nvalues at address of fx= %f",*fxPtr);
    printf("\nvalues at address of cht= %c\n",*chrPtr);

    return 0;
}
