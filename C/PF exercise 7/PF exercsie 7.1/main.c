#include <stdio.h>
#include <stdlib.h>
#define size 50
int main()
{
    char company[size],a;
    int i;
    printf("Enter organization name: ");
    gets(company);

    printf("\nAbbreviation of \"%s\" is: ",company);
    printf("%c",toupper(company[0]));
    for(i=1; i<=size ; i++)
    {
        if(company[i] == ' ')
        {
            a=toupper(company[++i]);
            printf("%c",a);
        }
    }

    printf("\n\n\n");
    return 0;
}
