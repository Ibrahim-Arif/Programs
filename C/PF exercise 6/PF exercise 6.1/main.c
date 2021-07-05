#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=10;
    char c='A';
    double f=25.5;
    int *iptr = &i;
    char *cptr = &c;

    printf("Value of i \t address of i \t value of iptr \t address of iptr \n");
    printf("%d \t\t  %p \t %p \t %p \t ",i,&i,iptr,&iptr);
    printf("\n\n\nderefrenced value of *iptr \t size of iptr \t size of i\n");
    printf("%d \t\t\t\t %d bytes \t %d bytes",*iptr,sizeof(iptr),sizeof(i));
    printf("\n--------------------------------------------------------------------\n\n");

    printf("Value of c \t address of c \t value of cptr \t address of cptr \n");
    printf("%c \t\t  %p \t %p \t %p \t ",c,&c,cptr,&cptr);
    printf("\n\n\nderefrenced value of *cptr \t size of cptr \t size of c\n");
    printf("%c \t\t\t\t %d bytes\t %d byte",*cptr,sizeof(cptr),sizeof(c));
    printf("\n--------------------------------------------------------------------\n");

    printf("\n\n\n");
    return 0;
}
