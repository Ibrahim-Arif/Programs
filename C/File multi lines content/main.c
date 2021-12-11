#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    char line[100], ch;
    char fName[10] ="file.txt";
    FILE *fptr;

    printf("Enter number of lines: ");
    scanf("%d",&n);
    fptr=fopen(fName , "w");
    if(fptr == 0)
        printf("File not found.\n");
    else
    {
        for(i=0 ; i<=n ; i++)
        {
            fgets(line, sizeof(line), stdin);
            //fputs(line, fptr);
            fprintf(fptr, line);
        }
        fclose(fptr);
    }
    printf("\n----------------------------------------------\n");
    printf("Printing file %s content: \n",fName);
    fptr=fopen(fName, "r");
    while( !feof(fptr) )
    {
        ch=fgetc(fptr);
        printf("%c",ch);
    }

    printf("\n");
    return 0;
}
