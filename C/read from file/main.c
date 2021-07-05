#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    char ch;
    int alpha=0,num=0,space=0,lower=0,upper=0;

    fptr=fopen("main.c","r");
    while( !feof(fptr) )
    {
        ch=fgetc(fptr);
        if(isalpha(ch))
            alpha++;
        else if(isdigit(ch))
            num++;
        else if(isspace(ch))
            space++;
        else if(isupper(ch))
            upper++;
        else if(islower(ch))
            lower++;
    }

    printf("alphabet: %d",alpha);
    printf("\nspace: %d",space);
    printf("\ndigit: %d",num);
    printf("\nupper: %d",upper);
    printf("\nlower: %d\n",lower);
    rewind(fptr);

    while(!feof(fptr))
    {
        ch=fgetc(fptr);
        ch=toupper(ch);
        printf("%c",ch);
    }

    fclose(fptr);
    return 0;
}
