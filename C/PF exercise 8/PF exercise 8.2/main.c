#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char string[300];

    fptr1=fopen("File 1.txt","r");
    fptr2=fopen("File 2.txt","w");

    while(  !feof(fptr1)  )
    {
        fgets(string,sizeof(string),fptr1);
        puts(string);
        fputs(string,fptr2);
    }
    printf("File 1 copied to File 2 successfully.");
    fclose(fptr1);
    fclose(fptr2);

    printf("\n\n");
    return 0;
}
