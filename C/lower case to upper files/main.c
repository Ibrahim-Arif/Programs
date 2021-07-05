#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr,*fptr1;
    int ch;
    char str[100];
    printf("Enter string: ");
    gets(str);

    fptr=fopen("file.txt","w");
    fputs(str,fptr);
    fclose(fptr);

    fptr=fopen("file.txt","r");
    fptr1=fopen("file.txt","r+");
    while( !feof(fptr) )
    {
        ch=fgetc(fptr);
        ch=ch-32;
        fputc((char)ch,fptr1);
        printf("%c",ch);
    }
    fclose(fptr);
    fclose(fptr1);

    printf("\n\n");
    return 0;
}
