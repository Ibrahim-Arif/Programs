#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char FileName[150];
    char arr[10000];
    int i=0;

    printf("Enter Path and Name of file: ");
    gets(FileName);

    fptr=fopen(FileName, "r");

    if(fptr == 0)
        printf("File not found :(");
    else
    {
        while( !feof(fptr) )
        {
            arr[i]=fgetc(fptr);
            i++;
        }
        arr[i] = '\0';
    }

    fclose(fptr);

    printf("\nContent in file %s:\n\n",FileName);
    for(i=0;arr[i] != '\0';i++)
        printf("%c",arr[i]);

    printf("\n\n");
    return 0;
}
